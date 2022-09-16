/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/16 20:04:34 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(const char *str)
{
	perror(str);
	exit(1);
}

void	free_map(t_map info)
{
	char	**map;

	map = info.map;
	while (*map)
	{
		free(*map);
		*map = NULL;
		map++;
	}
	free(info.map);
}

void	errfree_exit(const char *str, t_map info)
{
	free_map(info);
	perror(str);
	exit(1);
}

int	check_map(t_map info)
{
	char	**lines;
	char	*line;
	int		idx;
	int		l_idx;

	lines = info.map;
	l_idx = 0;
	while (*lines)
	{
		idx = 0;
		line = *lines;
		while (idx < info.len)
		{
			if (l_idx == 0 || l_idx == info.lines - 1)
			{
				if (line[idx] != '1')
					return (-1);
			}
			else
			{
				if (idx == 0 || idx == info.len - 1)
				{
					if (line[idx] != '1')
						return (-1);
				}
				else
				{
					if (line[idx] != '0' && line[idx] != '1' \
					&& line[idx] != 'C' && line[idx] != 'E' && line[idx] != 'P')
						return (-1);
				}
			}
			idx++;
		}
		lines++;
		l_idx++;
	}
	return (1);
}

void	draw_image_window(t_map *info, void *draw_ptr, int x, int y)
{
	void	*m_ptr;
	void	*w_ptr;

	m_ptr = info->mlx_ptr;
	w_ptr = info->win_ptr;
	mlx_put_image_to_window(m_ptr, w_ptr, draw_ptr, x, y);
}

void	draw_image(t_map *info, char elem, int x, int y)
{
	draw_image_window(info, info->g_ptr, x, y);
	draw_image_window(info, info->t_ptr, x, y);
	if (elem == '1')
	{
		draw_image_window(info, info->g_ptr, x, y);
		draw_image_window(info, info->t_ptr, x, y);
	}
	else if (elem == '0')
		draw_image_window(info, info->g_ptr, x, y);
	else if (elem == 'P')
	{
		draw_image_window(info, info->g_ptr, x, y);
		draw_image_window(info, info->p_ptr, x, y);
	}
	else if (elem == 'C')
	{
		draw_image_window(info, info->g_ptr, x, y);
		draw_image_window(info, info->c_ptr, x, y);
	}
	else if (elem == 'E')
	{
		draw_image_window(info, info->g_ptr, x, y);
		draw_image_window(info, info->e_ptr, x, y);
	}
}

void	draw_map(t_map *info)
{
	char	**map;
	int		x;
	int		y;

	map = info->map;
	x = 0;
	while (*map)
	{
		y = 0;
		while (y < info->len)
		{
			if (*map[y] == 'C')
				info->all_c++;
			draw_image(info, (*map)[y], y * LEN, x * LEN);
			y++;
		}
		x++;
		map++;
	}
}

void	get_ptrs(t_param *param, t_map *info, int *width, int *height)
{
	info->g_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./textures/grass.xpm", width, height);
	info->t_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./textures/tree.xpm", width, height);
	info->p_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./textures/plr.xpm", width, height);
	info->e_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./textures/exit.xpm", width, height);
	info->c_ptr = \
	mlx_xpm_file_to_image(info->mlx_ptr, "./textures/coin.xpm", width, height);
	draw_map(info);
}

void	draw_window(t_map *info)
{
	int		width;
	int		height;
	t_param	param;

	info->win_ptr = \
	mlx_new_window(info->mlx_ptr, LEN * info->len, LEN * info->lines, "solong");
	width = LEN;
	height = LEN;
	get_ptrs(&param, info, &width, &height);
	mlx_hook(info->win_ptr, X_EVENT_KEY_RELEASE, 0, &press_key, &param);
	mlx_loop(info->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*lines;
	char	*row;
	char	*temp;
	t_map	info;

	if (argc != 2)
		err_exit("Invaild map input");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("Invaild map file");
	row = get_next_line(fd);
	if (!row)
		err_exit("Invaild map file");
	else
	{
		info.len = ft_strlen(row) - 1;
		info.lines = 0;
		info.all_c = 0;
		info.c_cnt = 0;
		lines = ft_strdup("");
		while (row)
		{
			temp = (char *)malloc(sizeof(char) * ft_strlen(lines) + 1);
			ft_strlcpy(temp, lines, ft_strlen(lines) + 1);
			free(lines);
			lines = ft_strjoin(temp, row);
			free(row);
			info.lines++;
			free(temp);
			row = get_next_line(fd);
		}
		info.map = ft_split(lines, '\n');
		free(lines);
		free(row);
		close(fd);
	}
	if (check_map(info) > 0)
	{
		info.mlx_ptr = mlx_init();
		if (!info.mlx_ptr)
			errfree_exit("mlx init failed", info);
		draw_window(&info);
	}
	else
		errfree_exit("Invaild map input", info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/15 20:01:28 by jeykim           ###   ########.fr       */
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
	idx = 0;
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

void	draw_image(t_map info, char elem, int x, int y)
{
	if (elem == '1')
	{
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.g_ptr, x, y);
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.t_ptr, x, y);
	}
	else if (elem == '0')
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.g_ptr, x, y);
	else if (elem == 'P')
	{
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.g_ptr, x, y);
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.p_ptr, x, y);
	}
	else if (elem == 'C')
	{
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.g_ptr, x, y);
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.c_ptr, x, y);
	}
	else
	{
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.g_ptr, x, y);
		mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.e_ptr, x, y);
	}
}

void	draw_map(t_map info)
{
	char	**map;
	int		x;
	int		y;

	map = info.map;
	x = 0;
	while (*map)
	{
		y = 0;
		while (y < info.len)
		{
			draw_image(info, (*map)[y], x, y);
			y++;
		}
		x++;
		map++;
	}
}

void	get_ptrs(t_map info, int *width, int *height)
{
	void	*grass_ptr;
	void	*tree_ptr;
	void	*player_ptr;
	void	*exit_ptr;

	info.g_ptr = \
	mlx_xpm_file_to_image(info.mlx_ptr, "./textures/grass.xpm", width, height);
	info.t_ptr = \
	mlx_xpm_file_to_image(info.mlx_ptr, "./textures/tree.xpm", width, height);
	info.p_ptr = \
	mlx_xpm_file_to_image(info.mlx_ptr, "./textures/player.xpm", width, height);
	info.e_ptr = \
	mlx_xpm_file_to_image(info.mlx_ptr, "./textures/exit.xpm", width, height);
	info.e_ptr = \
	mlx_xpm_file_to_image(info.mlx_ptr, "./textures/coin.xpm", width, height);
	draw_map(info);
}

void	draw_window(t_map info)
{
	int		width;
	int		height;

	info.win_ptr = \
	mlx_new_window(info.mlx_ptr, 32 * info.len, 32 * info.lines, "so_long");
	width = 32;
	height = 32;
	get_ptrs(info, &width, &height);
	mlx_loop(info.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*lines;
	char	*row;
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
		lines = ft_strdup("");
		while (row)
		{
			lines = ft_strjoin(lines, row);
			info.lines++;
			row = get_next_line(fd);
		}
		info.map = ft_split(lines, '\n');
		free(lines);
	}
	if (check_map(info) > 0)
	{
		info.mlx_ptr = mlx_init();
		if (!info.mlx_ptr)
			errfree_exit("mlx init failed", info);
		draw_window(info);
	}
	else
		errfree_exit("Invaild map input", info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/22 20:26:23 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_map *info)
{
	info->lines = 0;
	info->c_cnt = 0;
	info->all_c = 0;
	info->p_cnt = 0;
	info->e_cnt = 0;
	info->step = 0;
}

int	free_lines_fd(char **lines, char **row, int fd, int ret)
{
	free(*lines);
	free(*row);
	close(fd);
	return (ret);
}

int	map_loop(char **temp, char **lines, char **row, int fd)
{
	*temp = (char *)malloc(sizeof(char) * ft_strlen(*lines) + 1);
	ft_strlcpy(*temp, *lines, ft_strlen(*lines) + 1);
	free(*lines);
	*lines = ft_strjoin(*temp, *row);
	free(*temp);
	free(*row);
	*row = get_next_line(fd);
	if (!*row)
		return (-1);
	*temp = ft_strtrim(*row, "\n");
	return (1);
}

int	get_map(t_map *info, int fd)
{
	char	*lines;
	char	*row;
	char	*temp;

	row = get_next_line(fd);
	if (!row)
		err_exit("Error\n");
	init_info(info);
	temp = ft_strtrim(row, "\n");
	info->len = ft_strlen(temp);
	free(temp);
	lines = ft_strdup("");
	while (row)
	{
		if (map_loop(&temp, &lines, &row, fd) < 0)
			break ;
		if ((info->len != (int)ft_strlen(temp)))
		{
			free(temp);
			return (free_lines_fd(&lines, &row, fd, -1));
		}
		free(temp);
	}
	info->map = ft_split(lines, '\n');
	return (free_lines_fd(&lines, &row, fd, 1));
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	info;
	char	*ptr;

	if (argc != 2)
		err_exit("Error");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("Error");
	ptr = ft_strrchr(argv[1], '.');
	if (!ptr || ft_memcmp(ptr, ".ber", 5) != 0)
		err_exit("Error");
	if (get_map(&info, fd) > 0 && check_map(&info) > 0 && info.all_c > 0)
	{
		info.mlx_ptr = mlx_init();
		if (!info.mlx_ptr)
			errfree_exit("Error", &info);
		draw_window(&info);
	}
	else
		err_exit("Error");
	return (0);
}

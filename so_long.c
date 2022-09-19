/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/19 15:55:59 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_map *info)
{
	info->lines = 1;
	info->c_cnt = 0;
	info->all_c = 0;
	info->p_cnt = 0;
	info->e_cnt = 0;
	info->step = 0;
}

void	get_map(t_map *info, int fd)
{
	char	*lines;
	char	*row;
	char	*temp;

	row = get_next_line(fd);
	if (!row)
		err_exit("Invaild map file");
	init_info(info);
	lines = ft_strdup("");
	while (row)
	{
		temp = (char *)malloc(sizeof(char) * ft_strlen(lines) + 1);
		ft_strlcpy(temp, lines, ft_strlen(lines) + 1);
		free(lines);
		lines = ft_strjoin(temp, row);
		free(row);
		(info->lines)++;
		free(temp);
		row = get_next_line(fd);
	}
	info->map = ft_split(lines, '\n');
	info->len = ft_strlen((info->map)[0]);
	free(lines);
	free(row);
	close(fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*row;
	t_map	info;

	if (argc != 2)
		err_exit("Invaild map input");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("Invaild map file");
	get_map(&info, fd);
	if (check_map(&info) > 0 && info.all_c > 0)
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

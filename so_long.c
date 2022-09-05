/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/05 17:51:19 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	err_exit(const char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	**head;
	t_map	*t_idx;
	int		idx;
	char	*line;

	if (argc != 2)
		err_exit("Invaild map input");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("Invaild map file");
	head = (t_map **)malloc(sizeof(t_map *));
	head = &t_idx;
	t_idx->next = NULL;
	line = get_next_line(fd);
	while (line)
	{
		idx = 0;
		while (line[idx] != '\0')
		{
			if (head == &t_idx && line[idx] != '1')
				err_exit("Invaild map file");
			idx++;
		}
		t_idx = (t_map *)malloc(sizeof(t_map));
		t_idx->line = line;
		t_idx = t_idx->next;
		line = get_next_line(fd);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:10 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/06 16:59:49 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	void	*ptr;

	if (argc != 2)
		err_exit("Invaild map input");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		err_exit("Invaild map file");
	head = (t_map **)malloc(sizeof(t_map *));
	head = &t_idx;
	line = get_next_line(fd);
	if (!line)
		err_exit("Invaild map file");
	while (line)
	{
		idx = 0;
		while (line[idx] != '\0')
		{
			if (head == &t_idx)
			{
				if (line[idx] != '1')
					err_exit("Invaild map file");
			}
			else
			{
				if (line[idx] != '1' && line[idx] != '0' && \
				line[idx] != 'C' && line[idx] != 'E' && line[idx] != 'P')
					err_exit("Invaild map file");
			}
			idx++;
		}
		if (head == &t_idx)
		{
			t_idx = (t_map *)malloc(sizeof(t_map));
			t_idx->length = idx;
			t_idx->line = line;
			t_idx->next = NULL;
		}
		else if ((*head)->length != idx) // 사용한 포인터들 모두 해제해줘야함 head 넘겨서
			err_exit("Invaild map file");
		else
		{
			t_idx->next = (t_map *)malloc(sizeof(t_map));
			t_idx->next->length = idx;
			t_idx->next->line = line;
			t_idx = t_idx->next;
			line = get_next_line(fd);
		}
	}
	ptr = mlx_init();
	mlx_new_window(ptr, 300, 300, "so_long");
}
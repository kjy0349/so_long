/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:44:26 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/21 10:35:35 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_cord(t_map *info, int *x, int *y)
{
	int	idx_x;
	int	idx_y;

	idx_y = 0;
	while (idx_y < info->lines)
	{
		idx_x = 0;
		while (idx_x < info->len)
		{
			if ((info->map)[idx_y][idx_x] == 'P')
			{
				*x = idx_x;
				*y = idx_y;
				return ;
			}
			idx_x++;
		}
		idx_y++;
	}
}

void	game_clear(t_map *info)
{	
	free_map(info);
	exit(0);
}

int	press_key(int keycode, t_map *info)
{
	if (keycode == KEY_W)
		move_w(info);
	else if (keycode == KEY_S)
		move_s(info);
	else if (keycode == KEY_A)
		move_a(info);
	else if (keycode == KEY_D)
		move_d(info);
	else if (keycode == KEY_ESC)
		exit(0);
	printf("%d\n", info->step);
	return (0);
}

int	exit_game(t_map *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}

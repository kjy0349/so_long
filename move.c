/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:14:38 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/22 10:37:56 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_map *info)
{
	char	elem;
	int		x;
	int		y;

	get_cord(info, &x, &y);
	elem = (info->map)[y - 1][x];
	if (elem == 'C')
		info->c_cnt++;
	if (elem == 'E' && info->all_c == info->c_cnt)
		game_clear(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y - 1][x] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

void	move_s(t_map *info)
{
	int		x;
	int		y;
	char	elem;

	get_cord(info, &x, &y);
	elem = (info->map)[y + 1][x];
	if (elem == 'C')
		info->c_cnt++;
	if (elem == 'E' && info->all_c == info->c_cnt)
		game_clear(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y + 1][x] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

void	move_a(t_map *info)
{
	int		x;
	int		y;
	char	elem;

	get_cord(info, &x, &y);
	elem = (info->map)[y][x - 1];
	if (elem == 'C')
		info->c_cnt++;
	if (elem == 'E' && info->all_c == info->c_cnt)
		game_clear(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y][x - 1] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

void	move_d(t_map *info)
{
	int		x;
	int		y;
	char	elem;

	get_cord(info, &x, &y);
	elem = (info->map)[y][x + 1];
	if (elem == 'C')
		info->c_cnt++;
	if (elem == 'E' && info->all_c == info->c_cnt)
		game_clear(info);
	else if (elem != '1' && elem != 'E')
	{
		(info->map)[y][x] = '0';
		(info->map)[y][x + 1] = 'P';
		info->step++;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		draw_map(info);
	}
}

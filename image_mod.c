/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:16:06 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/21 10:31:45 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_window(t_map *info)
{
	int		width;
	int		height;

	info->win_ptr = mlx_new_window(info->mlx_ptr, LEN * info->len, \
	LEN * info->lines, "so_long");
	width = LEN;
	height = LEN;
	get_ptrs(info, &width, &height);
	mlx_hook(info->win_ptr, X_EVENT_KEY_RELEASE, 0, &press_key, info);
	mlx_hook(info->win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, info);
	mlx_loop(info->mlx_ptr);
}

void	get_ptrs(t_map *info, int *width, int *height)
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
			draw_image(info, (*map)[y], y * LEN, x * LEN);
			y++;
		}
		x++;
		map++;
	}
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

void	draw_image_window(t_map *info, void *draw_ptr, int x, int y)
{
	void	*m_ptr;
	void	*w_ptr;

	m_ptr = info->mlx_ptr;
	w_ptr = info->win_ptr;
	mlx_put_image_to_window(m_ptr, w_ptr, draw_ptr, x, y);
}

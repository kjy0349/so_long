/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:40 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/21 10:05:58 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define LEN 32
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT   17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct map {
	int		len;
	int		lines;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*g_ptr;
	void	*p_ptr;
	void	*t_ptr;
	void	*e_ptr;
	void	*c_ptr;
	int		all_c;
	int		c_cnt;
	int		p_cnt;
	int		e_cnt;
	int		step;
}	t_map;

typedef struct param
{
	int	x;
	int	y;
}	t_param;

void	init_info(t_map *info);
int		get_map(t_map *info, int fd);
int		check_map(t_map *info);
void	free_map(t_map *info);
void	free_lines_fd(char **lines, char **row, int fd);
int		elem_check(t_map *info, char elem);
void	err_exit(const char *str);
void	errfree_exit(const char *str, t_map *info);
void	draw_window(t_map *info);
void	get_ptrs(t_map *info, int *width, int *height);
void	draw_map(t_map *info);
void	draw_image(t_map *info, char elem, int x, int y);
void	draw_image_window(t_map *info, void *draw_ptr, int x, int y);
void	move_w(t_map *info);
void	move_s(t_map *info);
void	move_a(t_map *info);
void	move_d(t_map *info);
int		press_key(int keycode, t_map *info);
void	game_clear(t_map *info);
void	get_cord(t_map *info, int *x, int *y);
int		exit_game(t_map *info);

#endif
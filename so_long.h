/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:40 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/16 19:59:17 by jeykim           ###   ########.fr       */
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
# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct map {
	int		len;
	int		lines;
	int		item;
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
}	t_map;

typedef struct param{
	int	x;
	int	y;
}	t_param;

#endif
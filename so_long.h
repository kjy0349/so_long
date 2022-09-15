/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:00:40 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/15 20:17:36 by jeykim           ###   ########.fr       */
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
}	t_map;

#endif
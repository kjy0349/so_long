/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeykim <jeykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:18:11 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/19 20:16:09 by jeykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(const char *str)
{
	perror(str);
	exit(1);
}

void	errfree_exit(const char *str, t_map *info)
{
	free_map(info);
	perror(str);
	exit(1);
}

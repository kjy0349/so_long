/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:18:11 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/21 09:39:50 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_exit(const char *str)
{
	printf("%s", str);
	exit(1);
}

void	errfree_exit(const char *str, t_map *info)
{
	free_map(info);
	printf("%s", str);
	exit(1);
}

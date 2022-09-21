/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:19:56 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/21 09:11:44 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map *info)
{
	char	**lines;
	int		idx;
	int		l_idx;

	lines = info->map;
	l_idx = 0;
	while (*lines)
	{
		idx = 0;
		while (idx < info->len)
		{
			if ((l_idx == 0 || l_idx == (info->lines) - 1 \
			|| idx == 0 || idx == info->len - 1) && (*lines)[idx] != '1')
				return (-1);
			else
				if (elem_check(info, (*lines)[idx]) == -1)
					return (-1);
			idx++;
		}
		lines++;
		info->lines++;
		l_idx++;
	}
	return (1);
}

void	free_map(t_map *info)
{
	char	**map;

	map = info->map;
	while (*map)
	{
		free(*map);
		*map = NULL;
		map++;
	}
	free(info->map);
	info->map = NULL;
}

int	elem_check(t_map *info, char elem)
{
	if (elem == '1' || elem == '0')
		return (1);
	else if (elem == 'P')
	{
		if (++(info->p_cnt) == 1)
			return (1);
		else
			return (-1);
	}
	else if (elem == 'C')
	{
		info->all_c++;
		return (1);
	}
	else if (elem == 'E')
	{
		if (++(info->e_cnt) == 1)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

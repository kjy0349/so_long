/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeyoung <jeyoung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:04:01 by jeykim            #+#    #+#             */
/*   Updated: 2022/09/21 10:22:16 by jeyoung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*return_ptr;

	ptr = (char *)s;
	return_ptr = 0x00;
	while (*ptr != '\0')
	{
		if (*ptr == (char)c)
			return_ptr = ptr;
		ptr++;
	}
	if ((char)c == '\0' && *ptr == '\0')
		return_ptr = ptr;
	return (return_ptr);
}

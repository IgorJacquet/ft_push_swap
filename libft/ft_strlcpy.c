/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:51:47 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:51:48 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;

	if (!(size))
		return (ft_strlen(src));
	x = 0;
	while (src[x] && x < size - 1)
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (ft_strlen(src));
}

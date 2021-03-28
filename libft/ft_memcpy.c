/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:49:47 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:49:48 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	x;
	char			*dsttemp;
	char			*srctemp;

	if (!(src || dst))
		return (0);
	dsttemp = (char *)dst;
	srctemp = (char *)src;
	x = 0;
	while (x < n)
	{
		dsttemp[x] = srctemp[x];
		x++;
	}
	return (dst);
}

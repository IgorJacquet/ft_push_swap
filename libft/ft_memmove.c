/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:49:53 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:49:54 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*dsttemp;
	unsigned char	*srctemp;

	if (!(dst || src))
		return (0);
	if (dst == src)
		return (dst);
	dsttemp = (unsigned char *)dst;
	srctemp = (unsigned char *)src;
	x = 0;
	if (srctemp > dsttemp)
		while (x < len)
		{
			dsttemp[x] = srctemp[x];
			x++;
		}
	else
		while (len-- > 0)
			dsttemp[len] = srctemp[len];
	return (dst);
}

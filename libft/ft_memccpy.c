/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:49:28 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:49:29 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		if (*(unsigned char *)(src + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (0);
}

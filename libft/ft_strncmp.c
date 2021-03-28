/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:52:03 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:52:03 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			x;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	x = 0;
	if (n < 1)
		return (0);
	if ((!c1) || (!c2))
		return (-1);
	while (c1[x] && c2[x] && x < n - 1 && c1[x] == c2[x])
		x++;
	return (c1[x] - c2[x]);
}

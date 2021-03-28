/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:52:26 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:52:26 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	x;
	size_t	slen;

	if (!(s))
		return (0);
	slen = ft_strlen(s);
	x = 0;
	if (start > slen)
		len = 0;
	else if (start + len > slen)
		len = slen - start;
	if ((str = malloc(sizeof(char) * len + 1)))
	{
		while (x < len)
		{
			str[x] = s[start + x];
			x++;
		}
		str[len] = 0;
	}
	return (str);
}

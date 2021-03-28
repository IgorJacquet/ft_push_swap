/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:51:31 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:51:31 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*copy;

	x = 0;
	while (s1 && s1[x])
		x++;
	if (!(copy = malloc(sizeof(char) * x + 1)))
		return (0);
	x = 0;
	while (s1 && s1[x])
	{
		copy[x] = s1[x];
		x++;
	}
	copy[x] = 0;
	return (copy);
}

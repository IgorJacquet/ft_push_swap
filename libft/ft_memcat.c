/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:49:17 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:49:18 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memcat(char *string, char *buf, int string_size, int buf_size)
{
	int		i;
	char	*string2;

	if (!(string2 = malloc(sizeof(char) * (string_size + buf_size + 1))))
	{
		if (string)
			free(string);
		return (NULL);
	}
	i = 0;
	while (i < string_size)
	{
		string2[i] = string[i];
		i++;
	}
	while (i < string_size + buf_size)
	{
		string2[i] = buf[i - string_size];
		i++;
	}
	if (string)
		free(string);
	string2[i] = '\0';
	return (string2);
}

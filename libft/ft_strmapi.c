/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:51:58 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:51:58 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	size;

	if (!(s) || !(f))
		return (0);
	size = ft_strlen(s);
	if (!(result = malloc(sizeof(char) * size + 1)))
		return (0);
	size = 0;
	while (s[size])
	{
		result[size] = f(size, s[size]);
		size++;
	}
	result[size] = 0;
	return (result);
}

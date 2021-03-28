/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:51:10 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:51:10 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_stradd_back(char **strs, char *new, int size)
{
	int		i;
	char	**newstrs;

	if (!(newstrs = malloc(sizeof(char *) * (size + 1))))
	{
		if (new)
			free(new);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		newstrs[i] = strs[i];
		i++;
	}
	newstrs[i] = new;
	if (strs)
		free(strs);
	return (newstrs);
}

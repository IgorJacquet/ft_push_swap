/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:50:54 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:50:56 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_complet_tab(const char *str, int min, int max)
{
	char	*tab;
	int		size;
	int		x;

	x = 0;
	size = max - min;
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (min < max)
	{
		tab[x] = str[min];
		min++;
		x++;
	}
	tab[x] = 0;
	return (tab);
}

static int	ft_settab(char const *s, char c, char **tab)
{
	int	t;
	int	max;
	int	min;

	t = 0;
	max = 0;
	min = 0;
	while (s[max])
	{
		if (s[max] == c)
		{
			if (!(tab[t++] = ft_complet_tab(s, min, max)))
				return (0);
			min = max + 1;
		}
		max++;
	}
	tab[t++] = ft_complet_tab(s, min, max);
	return (1);
}

static int	splitlen(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	while (s[i])
	{
		if (s[i] == c)
			size++;
		i++;
	}
	return (size);
}

char		**ft_split(char const *s, char c)
{
	int		size;
	char	**tab;

	if (!s)
		return (0);
	size = splitlen(s, c);
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (0);
	if (!(ft_settab(s, c, tab)))
		return (0);
	tab[size] = 0;
	return (tab);
}

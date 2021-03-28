/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:52:48 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:52:49 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_spliter(unsigned long long nbr, char *base, unsigned long size,
		char *chain)
{
	if (nbr >= size)
		ft_spliter((nbr / size), base, size, chain);
	while (*chain)
		chain++;
	*chain = base[nbr % size];
	*(chain + 1) = '\0';
}

static int	ft_ullen_base(unsigned long long nbr, unsigned long size)
{
	int x;

	x = 0;
	if (nbr >= size)
		x = ft_ullen_base((nbr / size), size);
	return (x + 1);
}

char		*ft_ultoa_base(unsigned long long nbr, char *base)
{
	int		size;
	int		len;
	char	*chain;

	size = ft_strlen(base);
	len = ft_ullen_base(nbr, (unsigned long long)size);
	if (!(chain = malloc(sizeof(char) * (len + 1))))
		return (0);
	*chain = '\0';
	ft_spliter(nbr, base, (unsigned long long)size, chain);
	return (chain);
}

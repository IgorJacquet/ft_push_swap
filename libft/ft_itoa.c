/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:47:48 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:47:50 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_itoa(long long nbr)
{
	int x;

	x = 0;
	if (nbr >= 10)
		x = ft_intlen(nbr / 10);
	else if (nbr < 0)
		x = ft_intlen(nbr * -1);
	return (x + 1);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		size;
	long	nb;

	nb = n;
	size = ft_intlen_itoa(nb);
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (0);
	if (nb < 0)
	{
		tab[0] = '-';
		nb = nb * -1;
	}
	tab[size--] = '\0';
	while (nb > 9)
	{
		tab[size--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	tab[size] = nb + '0';
	return (tab);
}

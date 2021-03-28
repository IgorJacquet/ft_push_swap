/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:06:00 by igor              #+#    #+#             */
/*   Updated: 2021/03/25 17:06:24 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	nbr;
	int					signe;

	nbr = 0;
	signe = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		if (nbr > 9223372036854775807)
			return ((signe + 1) / -2);
		str++;
	}
	return ((int)nbr * signe);
}

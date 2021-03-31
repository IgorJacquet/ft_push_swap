/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:39:25 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 17:39:49 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_atoi_check(int n, char *num)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (num[i] != '-')
			return (0);
		i++;
	}
	while (num[i] == '0')
		i++;
	if (n != 0)
	{
		if (num[i] != ft_abs(n) + '0')
			return (0);
	}
	else if (num[i] != 0)
		return (0);
	return (1);
}

int			ft_isint(char *num)
{
	long long	n;

	n = ft_atoi(num);
	if (n > 2147483647 || n < -2147483648 || ((n == 0 || n == -1)
	&& (!ft_atoi_check(n, num))))
		return (0);
	return (1);
}

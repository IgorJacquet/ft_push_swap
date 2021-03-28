/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:51:01 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:51:01 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	long sqrt;

	if (nb % 2)
		sqrt = 1;
	else
		sqrt = 2;
	while (sqrt * sqrt < nb)
		sqrt += 2;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (0);
}

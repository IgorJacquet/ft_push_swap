/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:17:01 by igor              #+#    #+#             */
/*   Updated: 2021/03/18 17:23:31 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_exit_write(char *msg, char *bonus, int value)
{
	write(2, msg, ft_strlen(msg));
	if (bonus)
	{
		write(2, bonus, ft_strlen(bonus));
		write(2, "\n", 1);
	}
	return (value);
}

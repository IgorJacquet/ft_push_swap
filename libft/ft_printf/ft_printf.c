/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:00:22 by gorban            #+#    #+#             */
/*   Updated: 2021/03/04 14:46:29 by tkleynts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_write(const char *array, long flags[6], int fd)
{
	int	zap;

	zap = 0;
	while (*(array + zap) && *(array + zap) != '%')
		zap++;
	ft_write(fd, (char *)array, zap, flags);
	return (zap);
}

int	ft_printf(const char *array, ...)
{
	va_list	ap;
	int		zap;
	int		zaap;
	long	flags[6];

	va_start(ap, array);
	while (*array)
	{
		if (*array == '%')
		{
			if (!(zap = check_comb(ap, (char *)(array + 1), flags)))
				return (-1);
			if ((zaap = parse(ap, flags)) < 0)
				return (-1);
		}
		else
			zap = ft_parse_write(array, flags, 1);
		array += zap;
	}
	va_end(ap);
	return (flags[5]);
}

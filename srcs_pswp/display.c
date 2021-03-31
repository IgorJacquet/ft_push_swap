/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:40:56 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:47:40 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stacks_2(int a, int b, t_stacks *s)
{
	ft_printf("\n------------------------\n");
	while (a < s->size_a || b < s->size_b)
	{
		if (a < s->size_a)
			ft_printf("%-16d", s->s_a[a]);
		else
			ft_printf("                ");
		if (b < s->size_b)
			ft_printf("%d\n", s->s_b[b]);
		else
			ft_printf("\n");
		a++;
		b++;
	}
	ft_printf("------------------------\nStack A         Stack B\n\n");
}

void	ft_print_stacks(t_stacks *s, int i)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (s->to_print)
	{
		s->count_op++;
		if (s->flag[1] && i)
			ft_printf("\x1B[32m");
		ft_printf("%s", s->to_print);
		if (s->flag[0])
			ft_print_stacks_2(a, b, s);
		if (s->flag[1] && i)
			ft_printf("\x1B[0m");
		if (s->flag[2] && i)
			ft_printf("Number of operations : %d\n", s->count_op);
	}
}

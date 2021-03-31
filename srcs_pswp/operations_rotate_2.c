/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:28:31 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:28:48 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stacks *s, int i)
{
	int tmp;

	if (s->size_a > 1)
	{
		if (i == 1)
			ft_print_stacks(s, 0);
		tmp = s->s_a[s->size_a - 1];
		ft_shift_plus(s->s_a, s->size_a);
		s->s_a[0] = tmp;
		if (i == 1)
			s->to_print = "rra\n";
	}
}

void	ft_rrb(t_stacks *s, int i)
{
	int tmp;

	if (s->size_b > 1)
	{
		if (i == 1)
			ft_print_stacks(s, 0);
		tmp = s->s_b[s->size_b - 1];
		ft_shift_plus(s->s_b, s->size_b);
		s->s_b[0] = tmp;
		if (i == 1)
			s->to_print = "rrb\n";
	}
}

void	ft_rrr(t_stacks *s)
{
	ft_print_stacks(s, 0);
	ft_rra(s, 0);
	ft_rrb(s, 0);
	s->to_print = "rrr\n";
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:26:08 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:27:08 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stacks *s, int i)
{
	int tmp;

	if (s->size_a > 1)
	{
		if (i == 1)
			ft_print_stacks(s, 0);
		tmp = s->s_a[0];
		ft_shift_minus(s->s_a, s->size_a);
		s->s_a[s->size_a - 1] = tmp;
		if (i == 1)
			s->to_print = "ra\n";
	}
}

void	ft_rb(t_stacks *s, int i)
{
	int tmp;

	if (s->size_b > 1)
	{
		if (i == 1)
			ft_print_stacks(s, 0);
		tmp = s->s_b[0];
		ft_shift_minus(s->s_b, s->size_b);
		s->s_b[s->size_b - 1] = tmp;
		if (i == 1)
			s->to_print = "rb\n";
	}
}

void	ft_rr(t_stacks *s)
{
	ft_print_stacks(s, 0);
	ft_ra(s, 0);
	ft_rb(s, 0);
	s->to_print = "rr\n";
}

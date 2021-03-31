/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:24:49 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:25:10 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stacks *stacks)
{
	if (stacks->size_b > 0)
	{
		ft_print_stacks(stacks, 0);
		stacks->size_b--;
		ft_shift_plus(stacks->s_a, stacks->size_a);
		stacks->size_a++;
		stacks->s_a[0] = stacks->s_b[0];
		ft_shift_minus(stacks->s_b, stacks->size_b);
		stacks->to_print = "pa\n";
	}
}

void	ft_pb(t_stacks *stacks)
{
	if (stacks->size_a > 0)
	{
		ft_print_stacks(stacks, 0);
		stacks->size_a--;
		stacks->size_b++;
		ft_shift_plus(stacks->s_b, stacks->size_b);
		stacks->s_b[0] = stacks->s_a[0];
		ft_shift_minus(stacks->s_a, stacks->size_a);
		stacks->to_print = "pb\n";
	}
}

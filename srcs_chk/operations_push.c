/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:05:34 by igor              #+#    #+#             */
/*   Updated: 2021/03/30 21:18:50 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_pa(t_stacks *stacks)
{
	if (stacks->size_b > 0)
	{
		stacks->size_b--;
		ft_shift_plus(stacks->s_a, stacks->size_a);
		stacks->size_a++;
		stacks->s_a[0] = stacks->s_b[0];
		ft_shift_minus(stacks->s_b, stacks->size_b);
	}
}

void	ft_pb(t_stacks *stacks)
{
	if (stacks->size_a > 0)
	{
		stacks->size_a--;
		stacks->size_b++;
		ft_shift_plus(stacks->s_b, stacks->size_b);
		stacks->s_b[0] = stacks->s_a[0];
		ft_shift_minus(stacks->s_a, stacks->size_a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:08:07 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:27:40 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_ra_rb(int *a, int size)
{
	int tmp;

	if (size > 1)
	{
		tmp = a[0];
		ft_shift_minus(a, size);
		a[size - 1] = tmp;
	}
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra_rb(stacks->s_a, stacks->size_a);
	ft_ra_rb(stacks->s_b, stacks->size_b);
}

void	ft_rra_rrb(int *a, int size)
{
	int tmp;

	if (size > 1)
	{
		tmp = a[size - 1];
		ft_shift_plus(a, size);
		a[0] = tmp;
	}
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rra_rrb(stacks->s_a, stacks->size_a);
	ft_rra_rrb(stacks->s_b, stacks->size_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:23:11 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:39:03 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stacks *stacks, int i)
{
	int	tmp;

	if (stacks->size_a > 1)
	{
		if (i == 1)
			ft_print_stacks(stacks, 0);
		tmp = stacks->s_a[0];
		stacks->s_a[0] = stacks->s_a[1];
		stacks->s_a[1] = tmp;
		if (i == 1)
			stacks->to_print = "sa\n";
	}
}

void	ft_sb(t_stacks *stacks, int i)
{
	int	tmp;

	if (stacks->size_b > 1)
	{
		if (i == 1)
			ft_print_stacks(stacks, 0);
		tmp = stacks->s_b[0];
		stacks->s_b[0] = stacks->s_b[1];
		stacks->s_b[1] = tmp;
		if (i == 1)
			stacks->to_print = "sb\n";
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_print_stacks(stacks, 0);
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	stacks->to_print = "ss\n";
}

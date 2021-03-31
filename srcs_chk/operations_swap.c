/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:03:06 by igor              #+#    #+#             */
/*   Updated: 2021/03/30 21:18:58 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_sa(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->s_a[0];
		stacks->s_a[0] = stacks->s_a[1];
		stacks->s_a[1] = tmp;
	}
}

void	ft_sb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->size_b > 1)
	{
		tmp = stacks->s_b[0];
		stacks->s_b[0] = stacks->s_b[1];
		stacks->s_b[1] = tmp;
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:57:03 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:59:31 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_handle_2(int i, int temp, t_stacks *s)
{
	while (++i < temp - 1)
		ft_rb(s, 1);
	if (temp > 0)
	{
		i = -1;
		temp = 0;
		while (++i <= s->size_b - 1)
			if (s->s_b[i] > s->s_b[temp] && s->s_b[i] < s->s_b[1])
				temp = i;
		if (temp < s->size_b / 2)
			ft_sb(s, 1);
		else
			ft_rb(s, 1);
	}
}

void		ft_handle_highest(t_stacks *s, int i, int temp)
{
	while (++i <= s->size_b - 1)
		if (s->s_b[i] > s->s_b[temp])
			temp = i;
	i = -1;
	if (temp == 0)
		return (ft_pa(s));
	if (temp >= s->size_b / 2)
		while (++i < s->size_b - temp)
			ft_rrb(s, 1);
	else
		ft_handle_2(i, temp, s);
	ft_pa(s);
}

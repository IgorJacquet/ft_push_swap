/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 23:37:39 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 06:54:37 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pivot(int argc, int *pivot, int *pivot2, t_stacks *s)
{
	if (argc > 110)
	{
		*pivot = ft_find_middle(s->s_a, s->size_a, 0.25);
		*pivot2 = ft_find_middle(s->s_a, s->size_a, 0.125);
	}
	else
	{
		*pivot = ft_find_middle(s->s_a, s->size_a, 0.5);
		*pivot2 = ft_find_middle(s->s_a, s->size_a, 0.25);
	}
}

void	ft_first_half(t_stacks *s, int pivot, int pivot2)
{
	while (ft_checkif_smaller(s->s_a, s->size_a, pivot) && s->size_a > 4)
	{
		if (s->s_a[0] < pivot && ft_3_higher(s->s_a, s->size_a, s->s_a[0]) &&
		(!ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) || s->size_a > 4))
			ft_pb(s);
		if (s->size_b && s->s_b[0] <= pivot2 && s->s_a[0] >= pivot)
			ft_rr(s);
		else if (s->size_b > 1 && s->s_b[0] < pivot2)
			ft_rb(s, 1);
		else if (s->s_a[0] >= pivot)
			ft_ra(s, 1);
	}
}

void	ft_morethan_3(t_stacks *s, int argc, int pivot, int pivot2)
{
	while (s->size_a > 3)
	{
		ft_pivot(argc, &pivot, &pivot2, s);
		while (ft_checkif_smaller(s->s_a, s->size_a, pivot) && s->size_a > 3)
		{
			if (s->s_a[0] <= pivot && ft_3_higher(s->s_a, s->size_a, s->s_a[0])
	&& (!ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) || s->size_a > 4))
				ft_pb(s);
			if (s->s_b[0] >= pivot2 && (s->s_a[0] >= pivot ||
		(ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) && s->size_a == 4)))
				ft_rr(s);
			else if (s->s_b[0] >= pivot2)
				ft_rb(s, 1);
			else if (s->s_a[0] >= pivot ||
		(ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) && s->size_a == 4))
				ft_ra(s, 1);
		}
		while (s->s_b[s->size_b - 1] > pivot2)
		{
			if (s->s_a[s->size_a - 1] < s->s_a[0])
				ft_rrr(s);
			else
				ft_rrb(s, 1);
		}
	}
}

void	ft_last_3(t_stacks *s)
{
	if (s->size_a == 3)
	{
		if (s->s_a[0] > s->s_a[1] && s->s_a[0] < s->s_a[2])
			ft_sa(s, 1);
		else if (s->s_a[0] > s->s_a[1] && s->s_a[1] > s->s_a[2])
		{
			ft_sa(s, 1);
			ft_rra(s, 1);
		}
		else if (s->s_a[0] < s->s_a[2] && s->s_a[2] < s->s_a[1])
		{
			ft_rra(s, 1);
			ft_sa(s, 1);
		}
		else if (s->s_a[0] > s->s_a[2] && s->s_a[2] > s->s_a[1])
			ft_ra(s, 1);
		else if (s->s_a[0] < s->s_a[1] && s->s_a[0] > s->s_a[2])
			ft_rra(s, 1);
	}
}

int		ft_cmd_parser(char **argv, int argc, t_stacks *s)
{
	int	i;
	int	pivot;
	int	pivot2;

	i = -1;
	while (++i < s->size_a)
		s->s_a[i] = ft_atoi(argv[i + s->flag[0] + s->flag[1] + s->flag[2] + 1]);
	ft_pivot(argc, &pivot, &pivot2, s);
	if (!ft_result_check(s))
		return (0);
	ft_first_half(s, pivot, pivot2);
	ft_morethan_3(s, argc, pivot, pivot2);
	ft_last_3(s);
	while (ft_result_check(s))
		ft_handle_highest(s, 0, 0);
	ft_print_stacks(s, 1);
	return (0);
}

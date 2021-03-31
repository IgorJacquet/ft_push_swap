/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:31:55 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:38:42 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_result_check(t_stacks *stacks)
{
	int i;

	i = -1;
	if (stacks->size_b)
		return (1);
	while (++i < stacks->size_a - 1)
	{
		if (stacks->s_a[i] > stacks->s_a[i + 1])
			return (1);
	}
	return (0);
}

int	ft_check_flags(char **argv, int argc, t_stacks *s, int i)
{
	while (++i < argc)
	{
		if (!ft_strncmp(argv[i], "-v", 3))
		{
			s->size_a--;
			s->flag[0]++;
		}
		else if (!ft_strncmp(argv[i], "-c", 3))
		{
			s->size_a--;
			s->flag[1]++;
		}
		else if (!ft_strncmp(argv[i], "-n", 3))
		{
			s->size_a--;
			s->flag[2]++;
		}
		else
			break ;
	}
	if (s->flag[0] > 1 || s->flag[1] > 1 || s->flag[2] > 1)
		return (ft_exit_write("Error\n", 0, -1));
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:11:40 by igor              #+#    #+#             */
/*   Updated: 2021/03/30 21:26:24 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			ft_argv_parse(char **argv, int argc)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (argc == 1)
		return (-1);
	while (++i < argc)
	{
		while (argv[i][++j])
			if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				return (ft_exit_write("Error\n", 0, -1));
		if (!ft_isint(argv[i]))
			return (ft_exit_write("Error\n", 0, -1));
		j = -1;
	}
	return (0);
}

static int	ft_cmd_list(char **str, t_stacks *stacks, int i)
{
	if (!ft_strncmp(str[i], "sa\n", 4))
		ft_sa(stacks);
	else if (!ft_strncmp(str[i], "sb\n", 4))
		ft_sb(stacks);
	else if (!ft_strncmp(str[i], "ss\n", 4))
		ft_ss(stacks);
	else if (!ft_strncmp(str[i], "pa\n", 4))
		ft_pa(stacks);
	else if (!ft_strncmp(str[i], "pb\n", 4))
		ft_pb(stacks);
	else if (!ft_strncmp(str[i], "ra\n", 4))
		ft_ra_rb(stacks->s_a, stacks->size_a);
	else if (!ft_strncmp(str[i], "rb\n", 4))
		ft_ra_rb(stacks->s_b, stacks->size_b);
	else if (!ft_strncmp(str[i], "rr\n", 4))
		ft_rr(stacks);
	else if (!ft_strncmp(str[i], "rra\n", 4))
		ft_rra_rrb(stacks->s_a, stacks->size_a);
	else if (!ft_strncmp(str[i], "rrb\n", 4))
		ft_rra_rrb(stacks->s_b, stacks->size_b);
	else if (!ft_strncmp(str[i], "rrr\n", 4))
		ft_rrr(stacks);
	else
		return (ft_exit_write("Error\n", 0, -1));
	return (0);
}

int			ft_cmd_parser(char **str, int size, t_stacks *stacks)
{
	int			i;

	i = -1;
	while (++i < size)
		if (ft_cmd_list(str, stacks, i) < 0)
			return (-1);
	return (0);
}

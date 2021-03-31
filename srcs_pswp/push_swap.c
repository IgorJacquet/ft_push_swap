/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:29:53 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:57:27 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_3_higher(int *s, int size, int i)
{
	int a;
	int count;

	a = -1;
	count = 0;
	while (++a < size)
	{
		if (s[a] > i)
			count++;
	}
	if (count > 2)
		return (1);
	return (0);
}

int		ft_stacks_init(t_stacks *stacks, int argc)
{
	int j;

	j = -1;
	if (!(stacks->s_a = malloc(sizeof(int) * (argc + 1))))
		return (ft_exit_write("Failed Malloc\n", 0, -1));
	if (!(stacks->s_b = malloc(sizeof(int) * (argc + 1))))
		return (ft_exit_write("Failed Malloc\n", 0, -1));
	while (++j <= argc)
		stacks->s_b[j] = 0;
	stacks->count_op = 0;
	stacks->size_b = 0;
	stacks->to_print = NULL;
	return (0);
}

int		ft_argv_parse(char **argv, int argc, t_stacks *s)
{
	int i;
	int j;
	int	ret;

	ret = 0;
	j = -1;
	s->size_a = -1;
	s->flag[0] = 0;
	s->flag[1] = 0;
	s->flag[2] = 0;
	if ((i = ft_check_flags(argv, argc, s, 0)) == -1)
		return (-1);
	while (i < argc)
	{
		while (argv[i][++j])
			if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				return (ft_exit_write("bError\n", 0, -1));
		j = -1;
		i++;
	}
	s->size_a += i;
	return (0);
}

int		main(int argc, char **argv)
{
	t_stacks	stacks;

	if (ft_argv_parse(argv, argc, &stacks) == -1)
		return (-1);
	ft_stacks_init(&stacks, argc);
	if (ft_cmd_parser(argv, argc, &stacks) == 0)
		ft_result_check(&stacks);
	free(stacks.s_a);
	free(stacks.s_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:41:16 by igor              #+#    #+#             */
/*   Updated: 2021/03/30 21:18:23 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_result_check(t_stacks *stacks)
{
	int i;

	i = -1;
	if (stacks->size_b)
	{
		write(2, "KO\n", 3);
		return ;
	}
	while (++i < stacks->size_a - 1)
	{
		if (stacks->s_a[i] > stacks->s_a[i + 1])
		{
			write(2, "KO\n", 3);
			return ;
		}
	}
	write(2, "OK\n", 3);
}

int		ft_stacks_init(t_stacks *stacks, int argc, char **argv)
{
	int j;

	j = -1;
	if (!(stacks->s_a = malloc(sizeof(int) * (argc + 1))))
		return (ft_exit_write("Failed Malloc\n", 0, -1));
	if (!(stacks->s_b = malloc(sizeof(int) * (argc + 1))))
		return (ft_exit_write("Failed Malloc\n", 0, -1));
	while (++j <= argc)
		stacks->s_b[j] = 0;
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	j = -1;
	while (++j < stacks->size_a)
		stacks->s_a[j] = ft_atoi(argv[j + 1]);
	return (0);
}

int		ft_stacks_check(t_stacks *s, int size)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < s->size_a)
	{
		while (++j < s->size_a)
			if (s->s_a[i] == s->s_a[j] && i != j)
				return (ft_exit_write("Error\n", 0, -2));
		j = -1;
	}
	return (size);
}

int		main(int argc, char **argv)
{
	char		**string;
	int			size;
	t_stacks	stacks;
	int			i;

	i = -1;
	if (ft_argv_parse(argv, argc) == -1)
		return (-1);
	if (!(string = malloc(sizeof(char *))))
		return (-1);
	if ((size = ft_line_reader(&string)) < -1)
		return (-1);
	if (ft_stacks_init(&stacks, argc, argv) < 0)
		return (-1);
	i = ft_stacks_check(&stacks, size);
	if (i > -2 && ft_cmd_parser(string, size, &stacks) == 0)
		ft_result_check(&stacks);
	free(stacks.s_a);
	free(stacks.s_b);
	while (--size >= 0)
		free(string[size]);
	free(string);
	return (0);
}

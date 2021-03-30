/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:41:16 by igor              #+#    #+#             */
/*   Updated: 2021/03/30 04:22:40 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		ft_realloc(char **str[2], char *new, int size)
{
	int	i;

	if (!new)
		return (0);
	i = 0;
	if (!(str[1] = malloc(sizeof(char *) * (size + 2))))
		return (ft_exit_write("Error\nFailed malloc\n", 0, -1));
	while (i < size)
	{
		str[1][i] = str[0][i];
		i++;
	}
	if (!(str[1][i] = ft_strdup(new)))
		return (ft_exit_write("Error\nFailed malloc\n", 0, -1));
	str[1][i + 1] = 0;
	if (str[0])
		free(str[0]);
	return (4219);
}

int			ft_line_reader(char ***string)
{
	char	*line;
	char	**str[2];
	int		r;
	int		size;

	size = -1;
	str[0] = NULL;
	str[1] = NULL;
	while ((r = get_next_line(0, &line)) >= 0)
	{
		if (!line[0])
			break ;
		if (r > 0 && !(line = ft_memcat(line, "\n", ft_strlen(line), 1)))
			return (ft_exit_write("malloc Error\n", 0, -1));
		if (ft_realloc(str, line, ++size) < 0)
			return (-2);
		str[0] = str[1];
		*string = str[1];
		free(line);
		if (r == 0)
			break ;
	}
	return (size + 1);
}

void	ft_shift_plus(int *stack, int size)
{
	while (size >= 0)
	{
		stack[size + 1] = stack[size];
		size--;
	}
}

void	ft_shift_minus(int *stack, int size)
{
	int j;

	j = -1;
	while (++j < size)
	{
		stack[j] = stack[j + 1];
	}
}

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

int		ft_cmd_parser(char **str, int size, t_stacks *stacks)
{
	int			i;

	i = -1;
	while (++i < size)
	{
		//ft_printf("len %d   |   diff : %d\n", ft_strlen(str[i]), ft_strncmp(str[i], "sa\n", 3));
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
	}
	return (0);
}

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

int	ft_stacks_init(t_stacks *stacks, int argc, char **argv)
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

int	ft_atoi_check(int n, char *num)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (num[i] != '-')
			return (0);
		i++;
	}
	while (num[i] == '0')
		i++;
	if (n != 0)
	{
		if (num[i] != ft_abs(n) + '0')
			return (0);
	}
	else if (num[i] != 0)
			return (0);
	return (1);
}

int	ft_isint(char *num)
{
	long long	n;

	n = ft_atoi(num);
	if (n > 2147483647 || n < -2147483648 || ((n == 0 || n == -1)
	&& (!ft_atoi_check(n, num))))
		return (0);
	return (1);
}

int ft_argv_parse(char **argv, int argc)
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

int main(int argc, char **argv)
{
	char				**string;
	int					size;
	t_stacks			stacks;
	int	i;

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
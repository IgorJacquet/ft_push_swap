/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:29:53 by igor              #+#    #+#             */
/*   Updated: 2021/03/30 17:03:24 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
		stack[j] = stack[j + 1];
}

void	ft_print_stacks(t_stacks *s)
{
	int a;
	int b;

	a = 0;
	b = 0;
	ft_printf("\n------------------------\n");
	while (a < s->size_a || b < s->size_b)
	{
		if (a < s->size_a)
			ft_printf("%-16d", s->s_a[a]);
		else
			ft_printf("                ");
		if (b < s->size_b)
			ft_printf("%d\n", s->s_b[b]);
		else
			ft_printf("\n");
		a++;
		b++;
	}
	ft_printf("------------------------\nStack A         Stack B\n\n");
}

void	ft_sa(t_stacks *stacks, int i)
{
	int	tmp;

	if (stacks->size_a > 1)
	{
		tmp = stacks->s_a[0];
		stacks->s_a[0] = stacks->s_a[1];
		stacks->s_a[1] = tmp;
		if (i == 1)
		{
			write(1, "sa\n", 3);
			if (stacks->flag[0])
				ft_print_stacks(stacks);
		}
	}
}

void	ft_sb(t_stacks *stacks, int i)
{
	int	tmp;

	if (stacks->size_b > 1)
	{
		tmp = stacks->s_b[0];
		stacks->s_b[0] = stacks->s_b[1];
		stacks->s_b[1] = tmp;
		if (i == 1)
		{
			write(1, "sb\n", 3);
			if (stacks->flag[0])
				ft_print_stacks(stacks);
		}
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks, 0);
	ft_sb(stacks, 0);
	write(1, "ss\n", 3);
	if (stacks->flag[0])
		ft_print_stacks(stacks);
}

void	ft_pa(t_stacks *stacks, int i)
{
	if (stacks->size_b > 0)
	{
		stacks->size_b--;
		ft_shift_plus(stacks->s_a, stacks->size_a);
		stacks->size_a++;
		stacks->s_a[0] = stacks->s_b[0];
		ft_shift_minus(stacks->s_b, stacks->size_b);
		if (i)
			ft_printf("\x1B[32m");
		write(1, "pa\n", 3);
		if (stacks->flag[0])
			ft_print_stacks(stacks);
		if (i)
			ft_printf("\x1B[0m");
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
		write(1, "pb\n", 3);
		if (stacks->flag[0])
			ft_print_stacks(stacks);
	}
}

void	ft_ra(t_stacks *s, int i)
{
	int tmp;

	if (s->size_a > 1)
	{
		tmp = s->s_a[0];
		ft_shift_minus(s->s_a, s->size_a);
		s->s_a[s->size_a - 1] = tmp;
		if (i == 1)
			write(1, "ra\n", 3);
		if (i && s->flag[0])
				ft_print_stacks(s);
	}
}

void	ft_rb(t_stacks *s, int i)
{
	int tmp;

	if (s->size_b > 1)
	{
		tmp = s->s_b[0];
		ft_shift_minus(s->s_b, s->size_b);
		s->s_b[s->size_b - 1] = tmp;
		if (i == 1)
			write(1, "rb\n", 3);
		if (i && s->flag[0])
				ft_print_stacks(s);
	}
}

void	ft_rr(t_stacks *s)
{
	ft_ra(s, 0);
	ft_rb(s, 0);
	write(1, "rr\n", 3);
	if (s->flag[0])
		ft_print_stacks(s);
}

void	ft_rra(t_stacks *s, int i)
{
	int tmp;

	if (s->size_a > 1)
	{
		tmp = s->s_a[s->size_a - 1];
		ft_shift_plus(s->s_a, s->size_a);
		s->s_a[0] = tmp;
		if (i == 1)
			write(1, "rra\n", 4);
		if (i && s->flag[0])
			ft_print_stacks(s);
	}
}

void	ft_rrb(t_stacks *s, int i)
{
	int tmp;

	if (s->size_b > 1)
	{
		tmp = s->s_b[s->size_b - 1];
		ft_shift_plus(s->s_b, s->size_b);
		s->s_b[0] = tmp;
		if (i == 1)
			write(1, "rrb\n", 4);
		if (i && s->flag[0])
			ft_print_stacks(s);
	}
}

void	ft_rrr(t_stacks *s)
{
	ft_rra(s, 0);
	ft_rrb(s, 0);
	write(1, "rrr\n", 4);
	if (s->flag[0])
		ft_print_stacks(s);
}

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

int		ft_check_endtab(int *s, int size, int ab)
{
	int	i;

	i = -1;
	if (ab == 1)
		while (++i < size - 1)
		{
			if (s[i] > s[i + 1])
				return (1);
		}
	else if (ab == 2)
		while (++i < size - 1)
		{
			if (s[i] < s[i + 1])
				return (1);
		}
	return (0);
}

int		ft_bigger_or_smaller(int *s, int size, int glo_size, int i)
{
	int	a;
	int b;

	a = 0;
	b = 0;
	while (b < size - 1)
		if (i < s[++b])
			a++;
	if (a >= glo_size / 2)
		return (1);
	return (0);
}

void	ft_b_to_a(t_stacks *s)
{
	while (s->size_b)
	{
		if (!ft_check_endtab(s->s_b, s->size_b, 2))
			if (ft_check_endtab(s->s_a, s->size_a, 1))
				return ;
		if (s->s_b[0] < s->s_b[1])
			ft_sb(s, 0);
		else if (s->s_b[0] < s->s_b[s->size_b - 1])
			ft_rb(s, 1);
		else if (s->s_b[0] > s->s_a[0])
			ft_pb(s);
		else
			ft_pa(s, 0);
	}
}

void	ft_selection_sort(int *array, int n)
{
	int i;
	int	j;
	int	min_element;
	int temp;

	i = 0;
	while (i < n-1)
	{
		min_element = i;
		j = i + 1;
		while (j < n)
		{
			if (array[j] < array[min_element])
				min_element = j;
			j++;
		}
		temp = array[min_element];
		array[min_element] = array[i];
		array[i] = temp;
		i++;
	} 
}

int		ft_find_middle(int *stack, int size, float index)
{
	int i;
	int	tab[size + 1];

	i = -1;
	while (++i < size)
		tab[i] = stack[i];
	ft_selection_sort(tab, size);
	return (tab[(int)(size * index)]);
}

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

int		ft_checkif_smaller(int *s, int size, int i)
{
	int a;

	a = -1;
	while (++a < size)
		if (s[a] < i)
			return (1);
	return (0);
}

void	ft_handle_highest(t_stacks *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (++i <= s->size_b - 1)
		if (s->s_b[i] > s->s_b[temp])
			temp = i;
	i = -1;
	if (temp == 0)
	{
		if (s->flag[1] && s->size_b == 1)
			ft_pa(s, 1);
		else
			ft_pa(s, 0);
		return ;
	}
	if (temp >= s->size_b / 2)
		while (++i < s->size_b - temp)
			ft_rrb(s, 1);
	else
	{
		while (++i < temp - 1)
			ft_rb(s, 1);
		if (temp > 0)
		{
			i = -1;
			temp = 0;
			while (++i <= s->size_b - 1)
			{
				if (s->s_b[i] > s->s_b[temp] && s->s_b[i] < s->s_b[1])
					temp = i;
			}
			if (temp < s->size_b / 2)
				ft_sb(s, 1);
			else
				ft_rb(s, 1);
		}
	}
	if (s->flag[1] && s->size_b == 1)
		ft_pa(s, 1);
	else
		ft_pa(s, 0);
}

int		ft_cmd_parser(char **argv, int argc, t_stacks *s)
{
	int	i;
	int	pivot;
	int	pivot2;

	i = -1;
	while (++i < s->size_a)
		s->s_a[i] = ft_atoi(argv[i + s->flag[0] + s->flag[1] + 1]);
	if (argc > 99)
	{
		pivot = ft_find_middle(s->s_a, s->size_a, 0.25);
		pivot2 = ft_find_middle(s->s_a, s->size_a, 0.125);
	}
	else
	{
		pivot = ft_find_middle(s->s_a, s->size_a, 0.5);
		pivot2 = ft_find_middle(s->s_a, s->size_a, 0.25);
	}
	if (!ft_result_check(s))
		return (0);
	while (ft_checkif_smaller(s->s_a, s->size_a, pivot) && s->size_a > 4)
	{
		if (s->s_a[0] < pivot && ft_3_higher(s->s_a, s->size_a, s->s_a[0]) &&
		(!ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) || s->size_a > 4))
			ft_pb(s);
		if (s->size_b && s->s_b[0] <= pivot2 && s->s_a[0] >= pivot)
			ft_rr(s);
		else if (s->size_b > 1 && s->s_b[0] <= pivot2)
			ft_rb(s, 1);
		else if (s->s_a[0] >= pivot)
			ft_ra(s, 1);
	}
	while (s->size_a > 3)
	{
		if (argc > 99)
		{
			pivot = ft_find_middle(s->s_a, s->size_a, 0.25);
			pivot2 = ft_find_middle(s->s_a, s->size_a, 0.125);
		}
		else
		{
			pivot = ft_find_middle(s->s_a, s->size_a, 0.5);
			pivot2 = ft_find_middle(s->s_a, s->size_a, 0.25);
		}
		while (ft_checkif_smaller(s->s_a, s->size_a, pivot) && s->size_a > 3)
		{
			if (s->s_a[0] <= pivot && ft_3_higher(s->s_a, s->size_a, s->s_a[0]) && (!ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) || s->size_a > 4))
				ft_pb(s);
			if (s->s_b[0] > pivot2 && (s->s_a[0] >= pivot || (ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) && s->size_a == 4)))
				ft_rr(s);
			else if (s->s_b[0] > pivot2)
				ft_rb(s, 1);
			else if (s->s_a[0] >= pivot || (ft_checkif_smaller(s->s_a, s->size_a, s->s_a[0]) && s->size_a == 4))
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
	while (ft_result_check(s))
		ft_handle_highest(s);
	return (0);
}

int	ft_stacks_init(t_stacks *stacks, int argc)
{
	int j;

	j = -1;
	if (!(stacks->s_a = malloc(sizeof(int) * (argc + 1))))
		return (ft_exit_write("Failed Malloc\n", 0, -1));
	if (!(stacks->s_b = malloc(sizeof(int) * (argc + 1))))
		return (ft_exit_write("Failed Malloc\n", 0, -1));
	while (++j <= argc)
		stacks->s_b[j] = 0;
	stacks->size_b = 0;
	return (0);
}

int ft_argv_parse(char **argv, int argc, t_stacks *s)
{
	int i;
	int j;
	int	ret;

	ret = 0;
	i = 0;
	j = -1;
	s->flag[0] = 0;
	s->flag[1] = 0;
	s->size_a = -1;
	if (!ft_strncmp(argv[1], "-c", 3) || (!ft_strncmp(argv[1], "-v", 3) && !ft_strncmp(argv[2], "-c", 3)))
	{
		s->size_a--;
		i++;
		s->flag[0] = 1;
	}
	if (!ft_strncmp(argv[1], "-v", 3) || (!ft_strncmp(argv[1], "-c", 3) && !ft_strncmp(argv[2], "-v", 3)))
	{
		s->size_a--;
		i++;
		s->flag[1] = 1;
	}
	while (++i < argc)
	{
		while (argv[i][++j])
			if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				return (ft_exit_write("Error\n", 0, -1));
		j = -1;
	}
	s->size_a += i;
	return (0);
}

int main(int argc, char **argv)
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
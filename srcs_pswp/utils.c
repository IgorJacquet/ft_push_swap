/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:29:05 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 00:22:25 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_checkif_smaller(int *s, int size, int i)
{
	int a;

	a = -1;
	while (++a < size)
		if (s[a] < i)
			return (1);
	return (0);
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
		stack[j] = stack[j + 1];
}

void	ft_selection_sort(int *array, int n)
{
	int i;
	int	j;
	int	min_element;
	int temp;

	i = 0;
	while (i < n - 1)
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

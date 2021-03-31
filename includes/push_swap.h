/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:56:13 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 15:23:18 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "struct.h"

void	ft_shift_plus(int *stack, int size);
void	ft_shift_minus(int *stack, int size);
int		ft_find_middle(int *stack, int size, float index);
int		ft_cmd_parser(char **argv, int argc, t_stacks *s);
int		ft_checkif_smaller(int *s, int size, int i);

void	ft_print_stacks(t_stacks *s, int i);
int		ft_check_flags(char **argv, int argc, t_stacks *s, int i);

void	ft_sa(t_stacks *stacks, int i);
void	ft_sb(t_stacks *stacks, int i);
void	ft_ss(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_ra(t_stacks *s, int i);
void	ft_rb(t_stacks *s, int i);
void	ft_rr(t_stacks *s);
void	ft_rra(t_stacks *s, int i);
void	ft_rrb(t_stacks *s, int i);
void	ft_rrr(t_stacks *s);

int		ft_3_higher(int *s, int size, int i);
void	ft_handle_highest(t_stacks *s, int i, int temp);
int		ft_result_check(t_stacks *stacks);

#endif

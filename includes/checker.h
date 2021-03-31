/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:18:50 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 17:04:05 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "struct.h"

int		ft_line_reader(char ***string, int size);

void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);

void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);

void	ft_ra_rb(int *a, int size);
void	ft_rr(t_stacks *stacks);
void	ft_rra_rrb(int *a, int size);
void	ft_rrr(t_stacks *stacks);

void	ft_shift_plus(int *stack, int size);
void	ft_shift_minus(int *stack, int size);
int		ft_isint(char *num);

int		ft_argv_parse(char **argv, int argc);
int		ft_cmd_parser(char **str, int size, t_stacks *stacks);

#endif

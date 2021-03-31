/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:52:35 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 01:01:56 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_stacks
{
	int		count_op;
	int		flag[3];
	int		*s_a;
	int		*s_b;
	int		size_a;
	int		size_b;
	char	*to_print;
}				t_stacks;

#endif

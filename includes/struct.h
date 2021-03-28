/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:52:35 by igor              #+#    #+#             */
/*   Updated: 2021/03/27 20:39:32 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_stacks
{
	int	*s_a;
	int	*s_b;
	int	size_a;
	int	size_b;
	int	flag[2];
}				t_stacks;

#endif
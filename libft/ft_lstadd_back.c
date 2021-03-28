/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:47:55 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:47:57 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	if (!(alst) || !(new))
		return ;
	if (!(*alst))
		return ;
	l = *alst;
	while (l->next)
		l = l->next;
	l->next = new;
}

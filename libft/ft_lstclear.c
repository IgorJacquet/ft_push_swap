/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:48:17 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:48:18 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			ft_lstdelone(l, del);
			l = l->next;
		}
		*lst = NULL;
	}
}

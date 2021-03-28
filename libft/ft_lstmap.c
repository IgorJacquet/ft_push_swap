/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 05:48:51 by igor              #+#    #+#             */
/*   Updated: 2021/03/28 05:48:52 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*result;
	t_list	*l;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	l = lst;
	if (!(result = ft_lstnew((*f)(l->content))))
		return (0);
	l = l->next;
	while (l)
	{
		if (!(temp = ft_lstnew((*f)(l->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp);
		l = l->next;
	}
	return (result);
}

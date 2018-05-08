/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:37:39 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 15:37:41 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*cur;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (!new)
		return (NULL);
	cur = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		cur->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!cur->next)
			return (NULL);
		cur = cur->next;
	}
	return (new);
}

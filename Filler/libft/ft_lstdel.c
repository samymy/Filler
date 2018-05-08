/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:34:50 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 15:34:52 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;

	if (!alst)
		return ;
	list = *alst;
	while (list)
	{
		del(list->content, list->content_size);
		next = list->next;
		free(list);
		list = next;
	}
	*alst = NULL;
}

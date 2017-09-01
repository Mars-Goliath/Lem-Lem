/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:24:02 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/22 22:41:41 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*new;

	if (!lst)
		return (NULL);
	if (!(start = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	start = f(lst);
	new = start;
	while (lst->next)
	{
		new->next = f(lst->next);
		lst = lst->next;
		new = new->next;
	}
	return (start);
}

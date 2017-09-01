/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:20:33 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/20 18:20:12 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*new;
	void		*c;
	size_t		s;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(c = (void *)malloc(sizeof(content_size))))
			return (NULL);
		ft_memcpy(c, content, content_size);
		s = content_size;
		new->content = c;
		new->content_size = s;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}

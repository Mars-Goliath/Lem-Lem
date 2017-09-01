/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 20:26:26 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/03 02:57:49 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		show(t_lem *lem)
{
	t_room *tmp;

	tmp = lem->room;
	while (tmp != NULL)
	{
		tmp->link = tmp->first_link;
		while (tmp->link != NULL)
			tmp->link = tmp->link->next;
		tmp = tmp->next;
	}
}

int			check_sons(t_lem *lem, t_room *room, t_link **link)
{
	*link = room->first_link;
	if ((*link)->room == NULL)
		return (0);
	while ((*link)->next != NULL)
	{
		if ((*link)->room->weight == 0)
			return (1);
		(*link) = (*link)->next;
	}
	if ((*link)->room->weight == 0)
		return (1);
	return (0);
}

int			path_search(t_lem *lem, t_room *room, int n)
{
	if (room == lem->end)
	 	n = 0;
	else
		room->weight = n;
	if (check_sons(lem, room, &room->link) == 0)
	{
		if (room != lem->end)
			path_search(lem, room->father, n - 1);
		else
			return (0);
	}
	if (room->link->room->weight == 0)
	{
		room->link->room->father = room;
		path_search(lem, room->link->room, n + 1);
	}
	return (0);
}

int			solve(t_lem *lem)
{
	if (lem->start == NULL)
		return (-6);
	if (lem->end == NULL)
		return (-7);
	lem->end->weight = -1;
	path_search(lem, lem->end, 0);
	if (lem->start->weight == 0)
		return (-5);
	ft_printf("%s\n", lem->buffer);
	path_carving(lem);
	the_march(lem);
	return (0);
}

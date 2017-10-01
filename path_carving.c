/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_carving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:41:42 by mlambert          #+#    #+#             */
/*   Updated: 2017/10/02 01:21:02 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			max_path(t_room *start, t_room *end)
{
	int n_end;
	int n_start;

	n_start = 0;
	n_end = 0;
	start->link = start->first_link;
	end->link = end->first_link;
	while (start->link != NULL)
	{
		start->link = start->link->next;
		n_start++;
	}
	while (end->link != NULL)
	{
		end->link = end->link->next;
		n_end++;
	}
	return (n_end >= n_start ? n_start : n_end);
}

t_room		*check_weight(t_room *room, t_room *room_link, t_room *tmp)
{
	if (room->weight > room_link->weight)
	{
		if (tmp != NULL)
		{
			if (tmp->weight > room_link->weight)
				tmp = room_link;
		}
		else if (room_link->path_locked == 0)
			tmp = room_link;
	}
	return (tmp);
}

t_room		*which_way(t_room *room)
{
	t_room *tmp;

	tmp = NULL;
	room->link = room->first_link;
	while (room->link->next != NULL)
	{
		tmp = check_weight(room, room->link->room, tmp);
		room->link = room->link->next;
	}
	tmp = check_weight(room, room->link->room, tmp);
	return (tmp);
}

void		path_carving(t_lem *lem)
{
	int		n;
	int		paths;
	t_room	*path_tmp;

	n = 1;
	path_tmp = lem->start;
	lem->paths = max_path(lem->start, lem->end);
	if (!(lem->path_array = ft_memalloc((unsigned int)(lem->paths))))
		return ;
	paths = lem->paths;
	while (path_tmp != lem->end)
	{
		path_tmp = which_way(path_tmp);
		path_tmp->path_locked = n;
	}
}

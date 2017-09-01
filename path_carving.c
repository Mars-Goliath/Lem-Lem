/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_carving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:41:42 by mlambert          #+#    #+#             */
/*   Updated: 2017/09/01 03:34:09 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			array_check(t_lem *lem, t_room *room)
{
	int	i;

	i = 0;
	while (i != lem->paths)
	{
		if (room->path_locked > 0 && lem->path_array[i] == room->path_locked)
				return (0);
		i++;
	}
	return (1);
}

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

int			flush(t_lem *lem, t_room *room)
{
	if (room->path_locked == 0)
		room->weight = 0;
	if (check_sons(lem, room, &room->link) == 0)
	{
		if (room != lem->end)
			flush(lem, room->father);
		else
			return (0);
	}
	if (room->link->room->weight == 0)
	{
		room->link->room->father = room;
		flush(lem, room->link->room);
	}
	return (0);
}

t_room		*check_weight(t_lem *lem, t_room *room, t_room *room_link, t_room *tmp)
{
	if (room->weight > room_link->weight)
	{
		if (tmp != NULL)
		{
			if (tmp->weight > room_link->weight && array_check(lem, room_link))
				tmp = room_link;
		}
		else if (room_link->path_locked == 0)			//  FIX recento OLOL JUST DELETE TO MAKE IT WORK;
			tmp = room_link;
	}
	return (tmp);
}

t_room		*which_way(t_lem *lem, t_room *room)
{
	t_room *tmp;

	tmp = NULL;
	room->link = room->first_link;
	while (room->link->next != NULL)
	{
		tmp = check_weight(lem, room, room->link->room, tmp);
		room->link = room->link->next;
	}
	tmp = check_weight(lem, room, room->link->room, tmp);
	return (tmp);
}

void		path_carving(t_lem *lem)
{
	int	n;
	int	paths;
	t_room	*path_tmp;

	n = 1;
	path_tmp = lem->start;
	lem->paths = max_path(lem->start, lem->end);
	if (!(lem->path_array = ft_memalloc((unsigned int)(lem->paths))))
		return ;
	paths = lem->paths;
	while (paths != 0)
	{
		while (path_tmp != lem->end)
		{
			path_tmp = which_way(lem, path_tmp);
			if (path_tmp == NULL)
			{
				lem->paths = 0;
				break;
			}
			path_tmp->path_locked = n;
		}
		if (paths != 0)
			lem->path_array[n - 1] = n;
		paths = paths != 0 ? paths - 1 : 0;
		flush(lem, lem->end);
		n++;
	}
}

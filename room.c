/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 01:35:01 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/03 05:00:08 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_format(t_lem *lem, char *line, int *i)
{
	int	xy;

	xy = 0;
	if (ft_isdigit(line[*i - 1]) != 1)
		return (-1);
	while (*i != 0 && xy != 2)
	{
		*i -= 1;
		while (xy != 2 && *i != 0 && line[*i] != ' ')
		{
			if (ft_isdigit(line[*i]) != 1)
				return (-1);
			*i -= 1;
		}
		if (line[*i] == ' ')
			xy += 1;
		if (*i != 0 && xy != 2 && line[*i] == ' ')
			if (ft_isdigit(line[*i - 1]) != 1)
				return (-1);
	}
	if (xy != 2)
		return (-1);
	return (0);
}

void		start_end_pointer(t_room *room, t_lem *lem, int start_1end_2)
{
	if (start_1end_2 == 1)
	{
		lem->start = room;
		room->ants_nb = lem->colony;
	}
	else
		lem->end = room;
}

t_room		*room_generation(t_lem *lem)
{
	t_room *tmp_start_list;
	t_room *tmp_end_list;

	tmp_start_list = lem->room;
	tmp_end_list = NULL;
	if (lem->room->name == NULL)
	{
		init_room(lem);
		return (lem->room);
	}
	while (lem->room->next != NULL)
		lem->room = lem->room->next;
	if (!(lem->room->next = (t_room *)malloc(sizeof(t_room))))
		errors(-2);	//a memdel of line would be a good idea i think. It means i should carry it around everywhere. Pretty much like my d"  "Yeah yeah, i get your point"  "...i meant like my dick johnny"  "..."
	lem->room = lem->room->next;
	init_room(lem);
	tmp_end_list = lem->room;
	lem->room = tmp_start_list;
	return (tmp_end_list);
}

int			room_specs(char *line, t_lem *lem, int start_1end_2)
{
	t_room	*salle;
	int		i;

	i = (int)ft_strlen(line);
	if (lem->phase == 1)
		return (-1);
	if (check_format(lem, line, &i) == -1)
		return (-2);
	if (*line == 'L')
		return (-2);
	salle = room_generation(lem);
	if (start_1end_2 != 0)
		start_end_pointer(salle, lem, start_1end_2);
	salle->name = ft_strsub(line, 0, i);
	return (0);
}

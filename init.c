/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 05:38:07 by mlambert          #+#    #+#             */
/*   Updated: 2017/06/30 20:18:45 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_room(t_lem *lem)
{
	lem->room->name = NULL;
	lem->room->ants_nb = 0;
	lem->room->path_locked = 0;
	lem->room->weight = 0;
	lem->room->coord_y = 0;
	lem->room->coord_x = 0;
	lem->room->next = NULL;
	if (!(lem->room->link = (t_link *)malloc(sizeof(t_link))))
		errors(-2);
	lem->room->first_link = lem->room->link;
	lem->room->link->next = NULL;
	lem->room->link->room = NULL;
}

void	init_lem(t_lem *lem)
{
	lem->colony = -1;
	lem->buffer = NULL;
	lem->paths = 0;
	lem->phase = 0;
	lem->match = 0;
	lem->start = NULL;
	lem->end = NULL;
	if (!(lem->room = (t_room *)malloc(sizeof(t_room))))
		errors(-2);
	init_room(lem);
}

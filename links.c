/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:38:15 by mlambert          #+#    #+#             */
/*   Updated: 2017/06/30 18:13:37 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*check_link(t_lem *lem, char *line, int	len)
{
	t_room	*tmp;

	tmp = lem->room;
	while (tmp->next && (lem->match = ft_strncmp(tmp->name, line, len)))
		tmp = tmp->next;
	if (lem->match != 0)
		lem->match = ft_strncmp(tmp->name, line, len);
	return (tmp);
}

int			check_tiret(char *line)
{
	int		i;
	int		tiret;

	i = 0;
	tiret = 0;
	while (line[i])
	{
		if (line[i] == '-')
			tiret += 1;
		i++;
	}
	return (tiret);
}

void		link_em(t_room *room_a, t_room *room_b)
{
	if (room_a->link->room == NULL)
		room_a->link->room = room_b;
	else
	{
		while (room_a->link->next != NULL)
			room_a->link = room_a->link->next;
		if (!(room_a->link->next = (t_link *)malloc(sizeof(t_link))))
			exit (0);
		room_a->link = room_a->link->next;
		room_a->link->room = room_b;
		room_a->link->next = NULL;
	}
	if (room_b->link->room == NULL)
		room_b->link->room = room_a;
	else
	{
		while (room_b->link->next != NULL)
			room_b->link = room_b->link->next;
		if (!(room_b->link->next = (t_link *)malloc(sizeof(t_link))))
			exit (0);
		room_b->link = room_b->link->next;
		room_b->link->next = NULL;
		room_b->link->room = room_a;
	}
}

int			links(t_lem *lem, char *line)
{
	int		i;
	t_room	*tmp;
	t_room	*tmp_2;

	i = 0;
	tmp = lem->room;
	tmp_2 = lem->room;
	fill_buffer(lem, line);
	if (check_tiret(line) != 1)
		return(-1);
	while(line[i] && line[i] != '-')
		i++;
	tmp = check_link(lem, line, i);
	if (lem->match != 0)
		return (-3);
	tmp_2 = check_link(lem, &line[i + 1], ft_strlen(line) - i);
	if (lem->match != 0)
		return (-3);
	if (ft_strcmp(tmp->name, tmp_2->name) != 0)
		link_em(tmp, tmp_2);
	return (0);
}

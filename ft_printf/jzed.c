/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jzed.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 03:33:15 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 04:36:29 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		jzed(char *flagtype, t_flag *flag)
{
	int	i;
	int	z;
	int	j;

	i = 0;
	z = 0;
	j = 0;
	while (flagtype[i])
	{
		if (flagtype[i] == 'j')
			j += 1;
		if (flagtype[i] == 'z')
			z += 1;
		i++;
	}
	if (j != 0)
		flag->j = 1;
	if (z != 0)
		flag->z = 1;
}

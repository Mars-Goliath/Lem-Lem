/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 00:26:16 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:32:03 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		modulo(t_flag *flag)
{
	int		i;
	char	buff[5];

	i = 0;
	ft_bzero(buff, 5);
	*buff = '%';
	flag->add_lrg = flag->largeur - 1;
	if (flag->largeur != 0)
	{
		if (flag->min == 0)
		{
			blank(flag);
			ft_buff_in_stone(buff, flag);
		}
		else
		{
			ft_buff_in_stone(buff, flag);
			blank(flag);
		}
	}
	else
		ft_buff_in_stone(buff, flag);
}

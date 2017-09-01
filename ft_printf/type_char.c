/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 04:43:34 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:54:24 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cero(t_flag *flag)
{
	char	c;
	wchar_t d;

	c = 0;
	d = 0;
	write(1, flag->buffer, ft_strlen(flag->buffer));
	ft_bzero(flag->buffer, MAX_BUFF_SIZE);
	flag->index = 0;
	if (flag->typ == 'c')
	{
		flag->read += 1;
		write(1, &c, 1);
	}
	else if (flag->typ == 'S')
	{
		flag->read += 6;
		write(1, "(null)", 6);
	}
	else
	{
		flag->read += 1;
		write(1, &d, 1);
	}
}

void		type_char(t_flag *flag, int c)
{
	char	buff[5];

	ft_bzero(buff, 5);
	*buff = (char)c;
	if (flag->largeur != 0)
	{
		flag->add_lrg = flag->largeur - 1;
		if (flag->min != 0)
		{
			ft_buff_in_stone(buff, flag);
			blank(flag);
		}
		else
		{
			blank(flag);
			ft_buff_in_stone(buff, flag);
		}
	}
	else
		ft_buff_in_stone(buff, flag);
	if (c == 0)
		cero(flag);
}

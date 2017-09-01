/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oo_lrg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:47:34 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:49:54 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			the_oo(t_flag *flag)
{
	if (flag->ash != 0)
	{
		flag->buffer[flag->index++] = '0';
		flag->read++;
		flag->add_lrg = flag->add_lrg != 0 ? (flag->add_lrg - 1) : 0;
		flag->add_prc = flag->add_prc != 0 ? (flag->add_prc - 1) : 0;
	}
}

void			oo_nothing(t_flag *flag)
{
	flag->add_lrg = flag->ash != 0 ? flag->add_lrg - 1 : flag->add_lrg;
	blank(flag);
	the_oo(flag);
}

void			oo_precis(t_flag *flag, char *str)
{
	if (flag->precision > flag->largeur)
	{
		the_oo(flag);
		zeroes(flag, str);
	}
	else
	{
		blank(flag);
		the_oo(flag);
		zeroes(flag, str);
	}
}

void			oo_nomin(char *str, t_flag *flag)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	if (flag->zero != 0)
	{
		the_oo(flag);
		blank(flag);
	}
	else if (flag->precision != -1)
		oo_precis(flag, str);
	else
		oo_nothing(flag);
	if (!(*str == '0' && flag->ash == 1 && flag->typ == 'o') && \
		(!(*str == '0' && flag->precision == 0)))
		ft_buff_in_stone(str, flag);
}

void			ft_oo_lrg(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	little_tweaks(flag, str);
	if (flag->min != 0)
	{
		the_oo(flag);
		zeroes(flag, str);
		if (!(*str == '0' && flag->ash == 1 && flag->typ == 'o') && \
			(!(*str == '0' && flag->precision == 0)))
			ft_buff_in_stone(str, flag);
		blank(flag);
	}
	else
		oo_nomin(str, flag);
}

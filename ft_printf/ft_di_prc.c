/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_prc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:32:05 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/18 04:11:24 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			little_tweaks(t_flag *flag, char *str)
{
	int	n;

	n = (int)ft_strlen(str);
	flag->sign = (*str == '-') ? 1 : 0;
	if ((flag->sign == 1) && (flag->precision != -1))
		flag->precision += 1;
	flag->add_prc = flag->precision > n ? flag->precision - n : 0;
	flag->add_lrg = flag->largeur > n ? flag->largeur - n : 0;
	if ((*str == '0') && (flag->precision == 0))
		*str = ' ';
}

void			minsign(t_flag *flag, char *str, int k)
{
	int i;

	i = 0;
	if (k == 0)
	{
		flag->buffer[flag->index++] = '-';
		flag->read++;
		*str = '0';
	}
	else if (k == 1)
	{
		flag->buffer[flag->index++] = '+';
		flag->read++;
	}
	if (flag->index == MAX_BUFF_SIZE)
	{
		write(1, flag->buffer, MAX_BUFF_SIZE);
		ft_bzero(flag->buffer, MAX_BUFF_SIZE);
		flag->index = 0;
	}
}

void			ft_di_prc(char *str, t_flag *flag)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(flag->precision == 0 && flag->largeur == 0 && (*str == '0')))
	{
		little_tweaks(flag, str);
		if ((flag->plus != 0) && (flag->sign != 1))
			scalpel(flag, 1);
		else if ((flag->blank != 0) && (flag->sign == 0))
			scalpel(flag, 0);
		if (flag->precision != -1)
			zeroes(flag, str);
		ft_buff_in_stone(str, flag);
	}
}

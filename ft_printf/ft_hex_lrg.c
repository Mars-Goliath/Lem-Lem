/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_lrg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 04:15:00 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/18 04:15:37 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			the_xx(t_flag *flag)
{
	if ((flag->ash != 0) && (flag->zero_case != 1))
	{
		flag->buffer[flag->index++] = '0';
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
		flag->buffer[flag->index++] = flag->typ == 'x' ? 'x' : 'X';
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
		flag->read += 2;
	}
}

void			hex_precis(t_flag *flag, char *str)
{
	if (flag->precision > flag->largeur)
	{
		the_xx(flag);
		zeroes(flag, str);
	}
	else
	{
		blank(flag);
		the_xx(flag);
		zeroes(flag, str);
	}
}

void			hex_nomin(char *str, t_flag *flag)
{
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	if (flag->zero != 0)
	{
		the_xx(flag);
		blank(flag);
	}
	else if (flag->precision != -1)
		hex_precis(flag, str);
	else
	{
		blank(flag);
		the_xx(flag);
	}
	ft_buff_in_stone(str, flag);
}

void			ft_hex_lrg(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->precision == 0 && *str == '0')
		flag->zero_case = 1;
	little_tweaks(flag, str);
	flag->add_lrg = flag->ash != 0 ? flag->add_lrg - 2 : flag->add_lrg;
	if (flag->min != 0)
	{
		the_xx(flag);
		if (flag->precision != -1)
			zeroes(flag, str);
		if (!(*str == '0' && flag->ash == 1 && flag->typ == 'o') && \
			(!(*str == '0' && flag->precision == 0)))
			ft_buff_in_stone(str, flag);
		blank(flag);
	}
	else
		hex_nomin(str, flag);
}

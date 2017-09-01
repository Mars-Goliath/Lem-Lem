/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:28:52 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 04:35:10 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		str_tweak(t_flag *flag, char *str)
{
	int i;
	int n;
	int prc;

	i = 0;
	n = ft_strlen(str);
	prc = flag->precision;
	flag->add_lrg = ((flag->precision != -1) && (n > prc)) ? \
		flag->largeur - prc : flag->largeur - n;
}

void		str_lrg(t_flag *flag, char *arg)
{
	str_tweak(flag, arg);
	if (flag->min != 0)
	{
		ft_buff_in_stone(arg, flag);
		blank(flag);
	}
	else
	{
		blank(flag);
		ft_buff_in_stone(arg, flag);
	}
}

void		str_prc(t_flag *flag, char *arg)
{
	if (flag->largeur != 0)
	{
		str_tweak(flag, arg);
		if (flag->min != 0)
		{
			str_in_chains(flag, arg);
			blank(flag);
		}
		else
		{
			blank(flag);
			str_in_chains(flag, arg);
		}
	}
	else
		str_in_chains(flag, arg);
}

void		str_in_chains(t_flag *flag, char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if ((flag->precision != -1) && (i == flag->precision))
			break ;
		flag->buffer[flag->index++] = str[i++];
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
}

void		type_str(t_flag *flag, char *arg)
{
	if (arg != NULL)
	{
		if (flag->precision != -1)
			str_prc(flag, arg);
		else
		{
			if (flag->largeur != 0)
				str_lrg(flag, arg);
			else
				ft_buff_in_stone(arg, flag);
		}
	}
	else
		ft_buff_in_stone("(null)", flag);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_lrg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 22:34:21 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/18 04:07:32 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			str_in_buff(char *buff, char *str, t_flag *flag)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buff[i] != '\0')
		i++;
	while (str[j])
		buff[i++] = str[j++];
	if ((flag->min != 0) && (flag->largeur != 0))
		while (i < flag->largeur)
			buff[i++] = ' ';
	ft_buff_in_stone(buff, flag);
}

void			fprecis(t_flag *flag, char *str)
{
	if ((flag->plus != 0 || flag->blank != 0) && (flag->sign == 0))
		flag->add_lrg--;
	if (flag->precision > flag->largeur)
	{
		if ((flag->typ != 'u') && (flag->plus != 0) && (flag->sign != 1))
			scalpel(flag, 1);
		else if (flag->typ != 'u' && flag->blank != 0)
			scalpel(flag, 0);
		zeroes(flag, str);
	}
	else
	{
		greffe(flag);
		if ((flag->typ != 'u') && (flag->plus != 0) && (flag->sign != 1))
			scalpel(flag, 1);
		else if (flag->typ != 'u' && flag->blank != 0)
			scalpel(flag, 0);
		zeroes(flag, str);
	}
}

void			f_no_prc_no_zero(t_flag *flag)
{
	if ((flag->plus != 0) || (flag->blank != 0))
		flag->add_lrg--;
	blank(flag);
	if ((flag->typ != 'u') && (flag->plus != 0) && (flag->sign != 1))
		scalpel(flag, 1);
	else if (flag->blank != 0)
		scalpel(flag, 0);
}

void			ft_no_min(char *str, t_flag *flag)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	if (flag->zero != 0)
	{
		if ((flag->typ != 'u') && (flag->plus != 0) && (flag->sign != 1))
			minsign(flag, str, 1);
		else if ((flag->typ != 'u') && (flag->blank != 0) && (flag->sign == 0))
			scalpel(flag, 0);
		if (((flag->plus != 0) || (flag->blank)) && (flag->sign == 0))
			flag->add_lrg--;
		if (flag->add_lrg != 0 && flag->sign != 0)
		{
			minsign(flag, str, 0);
			flag->add_lrg--;
		}
		blank(flag);
	}
	else if (flag->precision != -1)
		fprecis(flag, str);
	else
		f_no_prc_no_zero(flag);
	ft_buff_in_stone(str, flag);
}

void			ft_di_lrg(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	little_tweaks(flag, str);
	if (flag->min != 0)
	{
		if ((flag->typ != 'u') && (flag->plus != 0) && (flag->sign != 1))
			scalpel(flag, 1);
		else if ((flag->typ != 'u') && (flag->blank != 0) && (flag->sign == 0))
			scalpel(flag, 0);
		if (((flag->plus != 0) || (flag->blank != 0)) && (flag->sign == 0))
			flag->add_lrg--;
		if (flag->precision != -1)
			zeroes(flag, str);
		ft_buff_in_stone(str, flag);
		blank(flag);
	}
	else
		ft_no_min(str, flag);
}

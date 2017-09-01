/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_uni.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:13:12 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/05 18:38:57 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		castedwide(int n, t_flag *flag, wchar_t c)
{
	int		x;
	char	tab[16];

	n = 0;
	x = 0;
	ft_bzero(tab, 16);
	if (flag->typ != 'S')
	{
		x = (int)ft_strlen(tab);
		flag->add_lrg = n < flag->largeur ? flag->largeur - n : 0;
		blank(flag);
	}
	tab[0] = (char)c;
	ft_buff_in_stone(tab, flag);
}

void		wide(int n, t_flag *flag, char *tab)
{
	int		x;

	n = 0;
	x = 0;
	if (flag->typ != 'S')
	{
		x = (int)ft_strlen(tab);
		flag->add_lrg = n < flag->largeur ? flag->largeur - n : 0;
		blank(flag);
	}
	ft_buff_in_stone(tab, flag);
}

void		uni_uni(t_flag *flag, wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i])
		flag->n += size(str[i++]);
	flag->add_lrg = flag->largeur > flag->n ? flag->largeur - flag->n : 0;
	flag->on_off = 1;
	if (flag->largeur != 0 && flag->min == 0)
		blank(flag);
	while (*str)
	{
		unicode(flag, *str, 1);
		str++;
	}
	if (flag->largeur != 0 && flag->min != 0)
		blank(flag);
}

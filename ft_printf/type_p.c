/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:43:14 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/05 16:54:50 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	truc_immonde(t_flag *flag, char *str)
{
	int		n;

	n = (ft_strlen(str) + 2);
	flag->add_lrg = flag->largeur > n ? flag->largeur - n : 0;
	flag->add_prc = flag->precision > (n - 2) ? flag->precision - (n - 2) : 0;
	n = flag->add_prc;
	flag->add_prc = (*str == '0' && n != 0) ? flag->add_prc + 1 : flag->add_prc;
}

void	prc_buff(t_flag *flag)
{
	int	i;

	i = 0;
	while (i++ < flag->add_prc)
	{
		flag->buffer[flag->index++] = '0';
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
}

void	type_p(t_flag *flag, char *str)
{
	int		i;

	i = 0;
	truc_immonde(flag, str);
	if (flag->largeur != 0 && flag->min == 0 && flag->zero == 0)
		blank(flag);
	ft_buff_in_stone("0x", flag);
	if (flag->largeur != 0 && flag->zero != 0)
		blank(flag);
	if (flag->precision != -1)
		prc_buff(flag);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	if (!(flag->precision == 0 && *str == '0'))
		ft_buff_in_stone(str, flag);
	if (flag->largeur != 0 && flag->min == 1)
		blank(flag);
}

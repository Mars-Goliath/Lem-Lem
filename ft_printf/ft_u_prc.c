/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_prc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 04:01:05 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:25:04 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_u_prc(char *str, t_flag *flag)
{
	flag->n = (int)ft_strlen(str);
	flag->add_prc = flag->precision > flag->n ? flag->precision - flag->n : 0;
	flag->add_lrg = flag->largeur > flag->n ? flag->largeur - flag->n : 0;
	if (flag->precision != -1)
		zeroes(flag, str);
	if (!(*str == '0' && flag->precision == 0))
		ft_buff_in_stone(str, flag);
}

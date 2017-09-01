/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oo_prc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 01:43:08 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/18 07:17:02 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_oo_prc(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	flag->n = (int)ft_strlen(str);
	flag->add_prc = flag->precision > flag->n ? flag->precision - flag->n : 0;
	the_oo(flag);
	zeroes(flag, str);
	if (!(*str == '0' && flag->ash == 1 && flag->typ == 'o') && \
		(!(*str == '0' && flag->precision == 0)))
		ft_buff_in_stone(str, flag);
}

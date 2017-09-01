/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_prc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 04:33:53 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/18 04:23:47 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_hex_prc(char *str, t_flag *flag)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	flag->n = (int)ft_strlen(str);
	if ((flag->precision == 0 || flag->precision == -1) && *str == '0')
		flag->zero_case = 1;
	flag->add_prc = flag->precision > flag->n ? flag->precision - flag->n : 0;
	if ((flag->ash != 0) && (flag->zero_case != 1))
		the_xx(flag);
	zeroes(flag, str);
	if (!(*str == '0' && flag->ash == 1 && flag->typ == 'o') && \
		(!(*str == '0' && flag->precision == 0)))
		ft_buff_in_stone(str, flag);
}

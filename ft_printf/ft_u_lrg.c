/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_lrg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 04:01:19 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:20:48 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_u_lrg(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	little_tweaks(flag, str);
	if (flag->min != 0)
	{
		if (flag->precision != -1)
			zeroes(flag, str);
		if (!(*str == '0' && flag->precision == 0))
			ft_buff_in_stone(str, flag);
		blank(flag);
	}
	else
		ft_no_min(str, flag);
}

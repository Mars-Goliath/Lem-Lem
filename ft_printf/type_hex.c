/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:48:03 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/12 15:00:08 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	hex_cast_init(t_flag *flag, uintmax_t arg)
{
	if ((flag->min != 0) && (flag->zero != 0))
		(flag->zero = 0);
	if ((flag->plus != 0) && (flag->blank != 0))
		(flag->blank = 0);
	if ((flag->precision != -1) && (flag->zero != 0))
		(flag->zero = 0);
	if (flag->l == 1)
		return ((unsigned long)arg);
	else if (flag->ll == 1)
		return ((unsigned long long)arg);
	else if (flag->h == 1)
		return ((unsigned short)arg);
	else if (flag->hh == 1)
		return ((unsigned char)arg);
	else if (flag->j == 1)
		return ((uintmax_t)arg);
	else if (flag->z == 1)
		return ((size_t)arg);
	else
		return ((unsigned int)arg);
}

int			type_hex(t_flag *flag, char *str)
{
	if (((flag->typ == 'x') || (flag->typ == 'X')) && (flag->largeur != 0))
		ft_hex_lrg(str, flag);
	else if (((flag->typ == 'x') || (flag->typ == 'X')) && (flag->largeur == 0))
		ft_hex_prc(str, flag);
	return (0);
}

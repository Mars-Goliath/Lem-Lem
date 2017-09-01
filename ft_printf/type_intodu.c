/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_intodu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:55:59 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:56:00 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ou_cast_init(t_flag *flag, uintmax_t arg)
{
	if ((flag->min != 0) && (flag->zero != 0))
		(flag->zero = 0);
	if ((flag->plus != 0) && (flag->blank != 0))
		(flag->blank = 0);
	if ((flag->precision != -1) && (flag->zero != 0))
		(flag->zero = 0);
	if ((flag->l == 1) && ((flag->typ == 'o') || (flag->typ) == 'u'))
		return ((unsigned long)arg);
	else if ((flag->ll == 1) && ((flag->typ == 'o') || (flag->typ) == 'u'))
		return ((unsigned long long)arg);
	else if ((flag->h == 1) && ((flag->typ == 'o') || (flag->typ) == 'u'))
		return ((unsigned short)arg);
	else if ((flag->hh == 1) && ((flag->typ == 'o') || (flag->typ) == 'u'))
		return ((unsigned char)arg);
	else if (flag->j == 1)
		return ((uintmax_t)arg);
	else if (flag->z == 1)
		return ((size_t)arg);
	else
		return ((unsigned int)arg);
}

long long		di_cast_init(t_flag *flag, long long arg)
{
	if ((flag->min != 0) && (flag->zero != 0))
		(flag->zero = 0);
	if ((flag->plus != 0) && (flag->blank != 0))
		(flag->blank = 0);
	if ((flag->precision != -1) && (flag->zero != 0))
		(flag->zero = 0);
	if (flag->l == 1)
		return ((long)arg);
	else if (flag->ll == 1)
		return ((long long)arg);
	else if (flag->h == 1)
		return ((short)arg);
	else if (flag->hh == 1)
		return ((signed char)arg);
	else if (flag->j == 1)
		return ((intmax_t)arg);
	else if (flag->z == 1)
		return ((signed long)arg);
	else
		return ((int)arg);
}

int				type_intodu(t_flag *flag, char *str)
{
	if (((flag->typ == 'd') || (flag->typ == 'i')) && flag->largeur != 0)
		ft_di_lrg(str, flag);
	else if (((flag->typ == 'd') || (flag->typ == 'i')) && flag->largeur == 0)
		ft_di_prc(str, flag);
	else if ((flag->typ == 'o') && (flag->largeur != 0))
		ft_oo_lrg(str, flag);
	else if ((flag->typ == 'o') && (flag->largeur == 0))
		ft_oo_prc(str, flag);
	return (0);
}

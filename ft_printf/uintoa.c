/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 04:10:55 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 04:36:24 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		all(uintmax_t *nb, int base)
{
	uintmax_t	tmp;
	uintmax_t	n;

	n = 1;
	tmp = *nb;
	while (tmp > (uintmax_t)base - 1)
	{
		tmp = tmp / base;
		n++;
	}
	return (n);
}

void			type_uint(uintmax_t nb, t_flag *flag, int base)
{
	char		str[100];
	uintmax_t	i;

	i = all(&nb, base);
	ft_bzero(str, 100);
	str[i] = '\0';
	while (i > 0)
	{
		i--;
		str[i] = nb % base + '0';
		nb /= base;
	}
	if (flag->typ == 'o')
		type_intodu(flag, str);
	else if (flag->typ == 'u' && flag->largeur != 0)
		ft_u_lrg(str, flag);
	else
		ft_u_prc(str, flag);
}

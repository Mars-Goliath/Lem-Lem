/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 21:35:07 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/12 22:00:32 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init(t_flag *flag)
{
	flag->n = 0;
	flag->i = 0;
	flag->add_prc = 0;
	flag->add_lrg = 0;
	flag->on_off = 0;
	flag->tmp = 0;
	flag->zero_case = 0;
	flag->typ = 0;
	flag->sign = 0;
	flag->ash = 0;
	flag->plus = 0;
	flag->min = 0;
	flag->blank = 0;
	flag->zero = 0;
	flag->largeur = 0;
	flag->precision = -1;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->j = 0;
	flag->z = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greffe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 01:36:41 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:26:44 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	scalpel(t_flag *flag, int what)
{
	if (what == 0)
		flag->buffer[flag->index++] = ' ';
	else if (what == 1)
		flag->buffer[flag->index++] = '+';
	flag->read++;
	if (flag->index == MAX_BUFF_SIZE)
	{
		write(1, flag->buffer, MAX_BUFF_SIZE);
		ft_bzero(flag->buffer, MAX_BUFF_SIZE);
		flag->index = 0;
	}
}

void	blank(t_flag *flag)
{
	int		i;
	int		w;
	char	n;

	n = flag->zero == 1 ? '0' : ' ';
	i = 0;
	if (flag->typ == 'd' || flag->typ == 'i' || flag->typ == 'x' || \
		flag->typ == 'X' || flag->typ == 'o' || flag->typ == 'u')
		w = flag->add_lrg - flag->add_prc;
	else
		w = flag->add_lrg;
	while (i < w)
	{
		flag->buffer[flag->index++] = n;
		i++;
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
}

void	zeroes(t_flag *flag, char *str)
{
	int	i;

	i = 0;
	if (flag->typ == 'd' || flag->typ == 'i')
		if (((flag->add_prc != 0) || (flag->add_lrg != 0 && flag->zero != 0)) \
			&& (flag->sign != 0))
		{
			minsign(flag, str, 0);
			i = 1;
		}
	while (i < flag->add_prc)
	{
		flag->buffer[flag->index++] = '0';
		i++;
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
}

void	greffe(t_flag *flag)
{
	while (flag->i++ < (flag->add_lrg - flag->add_prc))
	{
		flag->buffer[flag->index++] = ' ';
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
}

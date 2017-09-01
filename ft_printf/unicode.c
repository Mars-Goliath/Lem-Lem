/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 22:25:49 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/05 18:38:46 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		size(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

void	uni_prc(t_flag *flag, wchar_t *str)
{
	int		j;

	j = 0;
	if ((flag->n + size(str[flag->i]) > flag->precision))
		flag->i--;
	flag->add_lrg = flag->largeur > flag->n ? flag->largeur - flag->n : 0;
	if (flag->largeur != 0 && flag->min == 0)
		blank(flag);
	if (flag->precision != 0)
		while (j <= flag->i)
			unicode(flag, str[j++], 1);
	if (flag->largeur != 0 && flag->min != 0)
		blank(flag);
}

void	binary_dance(wchar_t c, int i, char *tab, int *n)
{
	*n = 0;
	i = 0;
	while (c >> i)
		i++;
	ft_bzero(tab, 16);
	if (i > 7)
	{
		if (i > 11)
		{
			if (i > 16)
			{
				tab[(*n)++] = 0b11110000 | (0b00111111 & c >> 18);
				tab[(*n)++] = 0b10000000 | (0b00111111 & c >> 12);
			}
			else
				tab[(*n)++] = 0b11100000 | (0b00111111 & c >> 12);
			tab[(*n)++] = 0b10000000 | (0b00111111 & c >> 6);
		}
		else
			tab[(*n)++] = 0b11000000 | (0b00111111 & c >> 6);
		tab[(*n)++] = 0b10000000 | (c & 0b00111111);
	}
	else
		tab[*n++] = (char)c;
}

void	uni_str(t_flag *flag, wchar_t *str)
{
	int		tmp;
	int		norm;

	norm = flag->precision;
	tmp = 0;
	if (str != NULL)
	{
		if (flag->precision != -1)
		{
			while (str[flag->i] && (tmp += size(str[flag->i])) <= norm)
			{
				flag->i++;
				flag->n = tmp;
			}
			uni_prc(flag, str);
		}
		else
			uni_uni(flag, str);
	}
	else
		cero(flag);
}

int		unicode(t_flag *flag, wchar_t c, int k)
{
	char	tab[16];
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (c == 0 && flag->typ == 'C')
	{
		cero(flag);
		return (0);
	}
	if (c >= 128 && c <= 255)
		castedwide(n, flag, c);
	else
	{
		binary_dance(c, i, tab, &n);
		flag->on_off = (k == 0) ? 0 : 1;
		if (flag->on_off == 1)
			wide(n, flag, tab);
	}
	return (n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ramification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:40:41 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:19:32 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_lnp(char *flagtype, t_flag *flag, char *prc, char *lrg)
{
	int		i;
	int		j;

	i = 0;
	ft_bzero(lrg, 84);
	ft_bzero(prc, 84);
	while (flagtype[i])
	{
		j = 0;
		if (ft_isdigit((int)flagtype[i]) && (flagtype[i - 1] != '.'))
		{
			while ((flagtype[i] >= '0') && (flagtype[i] <= '9'))
				lrg[j++] = flagtype[i++];
			flag->largeur = ft_atoi(lrg);
		}
		j = 0;
		if (flagtype[i] == '.')
		{
			i++;
			while ((flagtype[i] >= '0') && (flagtype[i] <= '9'))
				prc[j++] = flagtype[i++];
			flag->precision = (*prc != '\0') ? ft_atoi(prc) : 0;
		}
		i++;
	}
}

void		ft_lnh(char *flagtype, t_flag *flag)
{
	int	i;
	int	l;
	int	h;

	l = 0;
	h = 0;
	i = 0;
	while (flagtype[i])
	{
		if (flagtype[i] == 'l')
			l += 1;
		if (flagtype[i] == 'h')
			h += 1;
		i++;
	}
	if ((l != 0) && (l % 2 == 0))
		flag->ll = 1;
	else if ((l != 0) && (l % 2 != 0))
		flag->l = 1;
	else if ((h != 0) && (h % 2 == 0))
		flag->hh = 1;
	else if ((h != 0) && (h % 2 != 0))
		flag->h = 1;
}

char		ft_get_type_in_the_char_bruh(char *flagtype, t_flag *flag)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (flagtype[i])
	{
		while (TYPES[j] != flagtype[i] && TYPES[j] != '\0')
			j++;
		if (flagtype[i] == '%')
			return (flagtype[i]);
		if (TYPES[j] == flagtype[i])
		{
			if ((flagtype[i] == 'D') || (flagtype[i] == 'O') || \
				(flagtype[i] == 'U'))
			{
				flagtype[i] = flagtype[i] + 32;
				flag->l = 1;
			}
			return (flagtype[i]);
		}
		j = 0;
		i++;
	}
	return ('z');
}

void		ft_filflag(char *flagtype, t_flag *flag)
{
	int		i;
	char	prc[84];
	char	lrg[84];

	i = 0;
	while (flagtype[i])
	{
		if (flagtype[i] == '#')
			flag->ash = 1;
		if (flagtype[i] == '+')
			flag->plus = 1;
		if (flagtype[i] == '-')
			flag->min = 1;
		if (flagtype[i] == ' ')
			flag->blank = 1;
		if ((flagtype[i] == '0') && (!(ft_isdigit((int)flagtype[i - 1]))))
			flag->zero = (flagtype[i - 1] != '.') ? 1 : 0;
		i++;
	}
	ft_lnp(flagtype, flag, prc, lrg);
	ft_lnh(flagtype, flag);
}

void		ft_ramification(char *flagtype, va_list ap, t_flag *flag)
{
	flag->typ = ft_get_type_in_the_char_bruh(flagtype, flag);
	ft_filflag(flagtype, flag);
	jzed(flagtype, flag);
	if (flag->typ == '%')
		modulo(flag);
	else if ((flag->typ == 'd') || (flag->typ == 'i'))
		ft_itoa_base(di_cast_init(flag, va_arg(ap, uintmax_t)), 10, flag);
	else if (flag->typ == 'u')
		type_uint(ou_cast_init(flag, va_arg(ap, uintmax_t)), flag, 10);
	else if (flag->typ == 'o')
		type_uint(ou_cast_init(flag, va_arg(ap, uintmax_t)), flag, 8);
	else if ((flag->typ == 'S') || (flag->typ == 's' && flag->l))
		uni_str(flag, va_arg(ap, wchar_t *));
	else if (flag->typ == 's')
		type_str(flag, va_arg(ap, char *));
	else if ((flag->typ == 'x') || (flag->typ == 'X'))
		hex(flag, hex_cast_init(flag, va_arg(ap, uintmax_t)));
	else if (flag->typ == 'C' || (flag->typ == 'c' && flag->l == 1))
		unicode(flag, va_arg(ap, wchar_t), 1);
	else if (flag->typ == 'c')
		type_char(flag, va_arg(ap, int));
	else if (flag->typ == 'p')
		hex(flag, (uintmax_t)va_arg(ap, void*));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:59:41 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/18 05:24:28 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int			big(long long *nb, int *k, int base)
{
	long long	tmp;
	int			n;

	n = 1;
	if (*nb > -9223372036854775807)
	{
		{
			*k = 1;
			*nb = *nb * -1;
			n++;
		}
		tmp = *nb;
		while (tmp > base - 1)
		{
			tmp = tmp / base;
			n++;
		}
	}
	else
		*k = 3;
	return (n);
}

int			alisneg(long long *nb, int *k, int base)
{
	long long	tmp;
	int			n;

	*k = 0;
	n = 1;
	if (*nb > -2147483648)
	{
		if (*nb < 0)
		{
			*k = 1;
			*nb = *nb * -1;
			n++;
		}
		tmp = *nb;
		while (tmp > base - 1)
		{
			tmp = tmp / base;
			n++;
		}
	}
	else if (*nb == -2147483648)
		*k = 2;
	else if (*nb < -2147483648)
		n = big(nb, k, base);
	return (n);
}

void		ft_itoa_base(long long nb, int base, t_flag *flag)
{
	char	str[100];
	int		i;
	int		k;

	i = alisneg(&nb, &k, base);
	ft_bzero(str, 100);
	if (k == 2)
		ft_strcpy(str, "-2147483648");
	else if (k == 3)
		ft_strcpy(str, "-9223372036854775808");
	else
	{
		str[i] = '\0';
		while (i-- > 0)
		{
			str[i] = nb % base + '0';
			nb /= base;
			if ((i == 1) && (k == 1))
			{
				i--;
				str[i] = '-';
			}
		}
	}
	type_intodu(flag, str);
}

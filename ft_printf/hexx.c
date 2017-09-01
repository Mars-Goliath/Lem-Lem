/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 03:27:06 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/24 03:30:12 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*mloc16(uintmax_t nb, uintmax_t *n, char *str)
{
	uintmax_t	tmp;

	ft_bzero(str, 100);
	tmp = nb;
	while (tmp > 15)
	{
		tmp = tmp / 16;
		*n += 1;
	}
	str[*n] = '\0';
	return (str);
}

void	hex(t_flag *flag, uintmax_t nb)
{
	uintmax_t		n;
	char			str[100];

	n = 1;
	mloc16(nb, &n, str);
	while (n-- > 0)
	{
		if (nb % 16 > 9)
			str[n] = flag->typ == 'x' ? (char)(nb % 16) + 87 : \
				(char)(nb % 16) + 55;
		else if (nb > 15)
			str[n] = nb % 16 + '0';
		else
		{
			if (nb > 15)
				str[n] = flag->typ == 'x' ? (char)nb + 87 : (char)nb + 55;
			else
				str[n] = nb + '0';
		}
		nb = nb / 16;
	}
	if (flag->typ == 'x' || flag->typ == 'X')
		type_hex(flag, str);
	else
		type_p(flag, str);
}

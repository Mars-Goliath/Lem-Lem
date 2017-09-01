/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:29:35 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/21 22:22:17 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_neglen(int *tmp, int *k, int *len)
{
	int		n;

	if (*tmp != -2147483648)
	{
		if (*tmp < 0)
		{
			*tmp = *tmp * -1;
			*k = 1;
		}
		n = *tmp;
		while (n > 9)
		{
			n = n / 10;
			++*len;
		}
		if (*k != 0)
			++*len;
	}
	else
		*k = 2;
}

char			*ft_itoa(int nb)
{
	char	*str;
	int		tmp;
	int		len;
	int		k;

	k = 0;
	len = 1;
	tmp = nb;
	ft_neglen(&tmp, &k, &len);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (k == 2)
	{
		str = (ft_strdup("-2147483648"));
		return (str);
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = (tmp % 10) + '0';
		tmp = tmp / 10;
		if (len == 0 && k == 1)
			str[len] = '-';
	}
	return (str);
}

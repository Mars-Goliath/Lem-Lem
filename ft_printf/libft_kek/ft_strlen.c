/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:23:43 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/05 17:08:16 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char			*who_is_it(unsigned long long *wide)
{
	char	*str;

	str = (char *)wide;
	if (*str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	else if (*++str == 0)
		return (str);
	return (NULL);
}

size_t			ft_strlen(const char *str)
{
	char				*zero;
	unsigned long long	*wide;

	zero = (char *)str;
	wide = (unsigned long long *)str;
	while ((unsigned long long)zero & 0b00000111)
	{
		if (*zero == 0)
			return (zero - str);
		++zero;
	}
	while (1)
	{
		if ((*wide - ZEROES_ONE) & ONE_ZEROES)
			if ((zero = who_is_it(wide)))
				return (zero - str);
		++wide;
	}
}

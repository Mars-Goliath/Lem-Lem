/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:19:13 by mlambert          #+#    #+#             */
/*   Updated: 2017/02/12 19:41:14 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;
	char	*str;

	i = 0;
	d = (char)c;
	str = (char *)s;
	while (s[i])
	{
		if (str[i] == d)
		{
			return (&str[i]);
		}
		i++;
	}
	if (str[i] == d)
		return (&str[i]);
	return (NULL);
}

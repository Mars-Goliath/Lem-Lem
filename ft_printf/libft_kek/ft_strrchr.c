/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:36:50 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 15:51:37 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == d)
			return ((char *)&s[i]);
		i--;
		if (s[i] == d)
			return ((char *)&s[i]);
	}
	return (NULL);
}

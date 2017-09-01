/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:05:51 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 12:39:54 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		s;

	i = ft_strlen(s1);
	s = 0;
	while (n != 0 && s2[s])
	{
		s1[i + s] = s2[s];
		n--;
		s++;
	}
	s1[i + s] = '\0';
	return (s1);
}

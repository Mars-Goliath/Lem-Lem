/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:03:15 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/22 15:28:04 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;
	size_t	b;
	size_t	j;

	j = 0;
	b = 0;
	l = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < len && big[b])
	{
		b = j;
		while (big[b] == little[l] && b < len && big[b])
		{
			b++;
			l++;
			if (little[l] == '\0')
				return ((char *)&big[b - l]);
		}
		l = 0;
		j++;
	}
	return (NULL);
}

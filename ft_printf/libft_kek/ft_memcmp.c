/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:37:24 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 15:33:21 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*src;
	int				p;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	p = 0;
	i = 0;
	while (n != 0)
	{
		if (dst[i] != src[i])
		{
			p = dst[i] - src[i];
			return (p);
		}
		i++;
		n--;
	}
	return (0);
}

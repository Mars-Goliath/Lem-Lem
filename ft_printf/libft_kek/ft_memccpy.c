/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:24:16 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 15:49:51 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n != 0)
	{
		dst2[i] = src2[i];
		if (src2[i] == d)
		{
			return ((unsigned char *)&dst[i + 1]);
		}
		i++;
		n--;
	}
	return (NULL);
}

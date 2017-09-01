/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:19:40 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/16 18:47:44 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (n != 0)
	{
		if (dst[i] == (unsigned char)c)
		{
			return (&dst[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}

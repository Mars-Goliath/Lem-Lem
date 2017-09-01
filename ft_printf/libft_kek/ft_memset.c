/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:19:23 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/22 16:48:21 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tab;
	unsigned char	d;

	d = (unsigned char)c;
	tab = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		tab[i] = d;
		i++;
	}
	return (b);
}

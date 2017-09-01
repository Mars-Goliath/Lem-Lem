/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:47:37 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/13 22:23:50 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}

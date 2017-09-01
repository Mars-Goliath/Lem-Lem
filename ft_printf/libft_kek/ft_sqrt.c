/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:51:54 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/22 23:01:31 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		square;

	square = 1;
	while (square * square <= nb)
	{
		if (square * square == nb)
		{
			return (square);
		}
		square++;
	}
	return (0);
}

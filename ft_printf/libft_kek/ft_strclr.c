/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:11:02 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 14:07:42 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strclr(char *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (s != NULL)
	{
		n = ft_strlen(s);
		while (i < n)
		{
			s[i] = '\0';
			i++;
		}
	}
}

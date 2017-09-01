/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:57:17 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/21 22:10:39 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	l;
	size_t	j;

	j = 0;
	i = 0;
	l = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[j])
	{
		i = j;
		while ((big[i] == little[l]) && big[i])
		{
			l++;
			i++;
			if (little[l] == '\0')
				return ((char *)&big[j]);
		}
		l = 0;
		j++;
	}
	return (NULL);
}

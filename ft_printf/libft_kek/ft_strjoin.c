/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:39:56 by mlambert          #+#    #+#             */
/*   Updated: 2016/12/23 22:42:53 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*nex;
	size_t	top;

	if (!s2)
		return (NULL);
	if (!s1)
		return (NULL);
	top = (ft_strlen(s1) + ft_strlen(s2));
	if (!(nex = (char *)malloc(sizeof(char) * top + 1)))
		return (NULL);
	ft_strcpy(nex, s1);
	ft_strcat(nex, s2);
	nex[top] = '\0';
	return (nex);
}

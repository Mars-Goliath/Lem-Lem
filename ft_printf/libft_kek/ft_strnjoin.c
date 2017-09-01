/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:10:34 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 14:31:34 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*nex;

	if (!s1 || !s2)
		return (NULL);
	if (!(nex = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len + 1))))
		return (NULL);
	ft_strcpy(nex, s1);
	ft_strncat(nex, s2, len);
	return (nex);
}

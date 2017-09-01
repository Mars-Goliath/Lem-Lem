/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:49:18 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/21 22:11:51 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(const char *s)
{
	int			start;
	int			end;
	char		*dest;

	if (s == NULL)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	end++;
	if ((dest = (char *)malloc((end - start) * sizeof(char))) == NULL)
		return (NULL);
	dest = ft_strsub(s, start, (end - start));
	if (dest)
		dest[end] = '\0';
	return (dest);
}

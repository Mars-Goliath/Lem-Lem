/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:49:01 by mlambert          #+#    #+#             */
/*   Updated: 2016/11/23 13:52:26 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_letters(const char *s, char c, int g, int *n)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	while (s[*n] == c)
		++*n;
	t = *n;
	while (s[*n] != c && s[*n] != '\0')
	{
		++*n;
		g++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (g + 1))))
		return (NULL);
	str[g] = '\0';
	while (i < g)
	{
		str[i] = s[t + i];
		i++;
	}
	return (str);
}

static int		ft_dissection(const char *str, char c)
{
	size_t	i;
	int		w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (i < ft_strlen(str))
			w++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (w);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		z;
	char	**tab;

	z = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = ((char **)malloc(sizeof(char *) * (ft_dissection(s, c) + 1)))))
		return (NULL);
	while (i < ft_dissection(s, c))
	{
		tab[i] = ft_letters(s, c, 0, &z);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

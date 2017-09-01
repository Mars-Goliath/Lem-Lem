/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:01:56 by mlambert          #+#    #+#             */
/*   Updated: 2017/03/05 17:44:48 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <strings.h>

void	ft_buff_in_stone(char *str, t_flag *flag)
{
	int		i;

	i = 0;
	while (str[i])
	{
		flag->buffer[flag->index++] = str[i++];
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
}

int		ft_before_type(const char *format, t_flag *flag, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
			break ;
		flag->buffer[flag->index++] = format[i++];
		flag->read++;
		if (flag->index == MAX_BUFF_SIZE)
		{
			write(1, flag->buffer, MAX_BUFF_SIZE);
			ft_bzero(flag->buffer, MAX_BUFF_SIZE);
			flag->index = 0;
		}
	}
	return (i);
}

int		ft_check(char *flagtype)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (flagtype[i])
	{
		while (TYPES[j] != flagtype[i] && TYPES[j] != '\0')
		{
			if (flagtype[i] == '%')
				return (1);
			j++;
		}
		if (TYPES[j] == flagtype[i])
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int		ft_parsing(char *flgt, const char *format, t_pars1 *pars1, t_flag *flag)
{
	int	i;
	int	j;

	j = 0;
	i = pars1->index;
	if (format[i] == '\0')
		return (0);
	i = ft_before_type(format, flag, i);
	while (ft_check(flgt) == 0 && format[i] != '\0')
	{
		if (ft_strchr(VALID, (int)format[i]) == NULL)
			break ;
		flgt[j++] = format[i++];
	}
	if (!(ft_check(flgt)))
	{
		ft_before_type(&format[i], flag, 0);
		return (0);
	}
	pars1->index = i;
	return (1);
}

int		ft_printf(const char *format, ...)
{
	t_pars1 pars1;
	t_flag	flag;
	va_list ap;

	va_start(ap, format);
	ft_bzero(&pars1, sizeof(pars1));
	ft_bzero(&flag, sizeof(t_flag));
	flag.precision = -1;
	while (ft_parsing(pars1.flagtype, format, &pars1, &flag) != 0)
	{
		ft_ramification(pars1.flagtype, ap, &flag);
		init(&flag);
		ft_bzero(pars1.flagtype, 100);
	}
	if (flag.buffer[0] != '\0')
		write(1, flag.buffer, ft_strlen(flag.buffer));
	va_end(ap);
	return (flag.read);
}

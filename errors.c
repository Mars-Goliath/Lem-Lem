/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:49:46 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/03 05:19:51 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		errors(int error_type)
{
	if (error_type == -1)
		ft_printf("%s", "ERROR : Unexpected Input");
	else if (error_type == -2)
		ft_printf("%s", "ERROR : BAD ROOM INFO");
	else if (error_type == -3)
		ft_printf("%s", "ERROR : YOUR ROOM ISNT REGISTERED");
	else if (error_type == -4)
		ft_printf("%s", "ERROR : WOW, FAIL MALLOC. I'M OUTTA HERE. ");
	else if (error_type == -5)
		ft_printf("%s\n", "ERROR : UNSOLVABLE MAP");
	else if (error_type == -6)
		ft_printf("%s\n", "ERROR : WHERE DOES IT STARTS ?");
	else if (error_type == -7)
		ft_printf("%s\n", "ERROR : NEVER ENDING MAZE");
	else if (error_type == -8)
		ft_printf("%s\n", "ERROR : TOO MANY ARGUMENTS");
	else if (error_type == -9)
		ft_printf("%s\n", "ERROR : BAD ROOM INFO");
	exit(0);
}

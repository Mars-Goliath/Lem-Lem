/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:48:21 by mlambert          #+#    #+#             */
/*   Updated: 2017/06/07 04:14:16 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_BUFF_SIZE 128
# define TYPES "sSpdDioOuUxXcC%"
# define VALID " .#+-lhjzsSpdDioOuUxXcC%0123456789"

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct		s_pars1
{
	char		flagtype[100];
	int			index;
}					t_pars1;

typedef struct		s_flag
{
	char	buffer[MAX_BUFF_SIZE];
	int		index;
	int		read;
	int		on_off;

	int		track;

	int		n;
	int		i;
	int		add_prc;
	int		add_lrg;

	int		tmp;

	int		zero_case;

	char	typ;
	int		sign;
	int		ash;
	int		plus;
	int		min;
	int		blank;
	int		zero;
	int		largeur;
	int		precision;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		j;
	int		z;
}					t_flag;

int					ft_printf(const char *format, ...);
void				ft_ramification(char *flagtype, va_list ap, t_flag *flag);
int					type_intodu(t_flag *flag, char *str);
void				ft_di_lrg(char *str, t_flag *flag);
void				ft_di_prc(char *str, t_flag *flag);
void				ft_no_min(char *str, t_flag *flag);
void				ft_itoa_base(long long nb, int base, t_flag *flag);
void				ft_buff_in_stone(char *str, t_flag *flag);
void				str_in_buff(char *buff, char *str, t_flag *flag);

void				ft_oo_lrg(char *str, t_flag *flag);
void				ft_oo_prc(char *str, t_flag *flag);
void				the_oo(t_flag *flag);
void				ft_hex_lrg(char *str, t_flag *flag);
void				ft_hex_prc(char *str, t_flag *flag);
void				the_xx(t_flag *flag);

void				jzed(char *flagtype, t_flag *flag);

void				type_str(t_flag *flag, char *arg);
void				blank(t_flag *flag);
void				zeroes(t_flag *flag, char *str);
void				str_lrg(t_flag *flag, char *str);
void				str_prc(t_flag *flag, char *arg);
void				str_in_chains(t_flag *flag, char *str);
void				minsign(t_flag *flag, char *str, int k);
void				little_tweaks(t_flag *flag, char *str);

void				init(t_flag *flag);

int					type_hex(t_flag *flag, char *str);
void				type_p(t_flag *flag, char *str);
void				type_char(t_flag *flag, int c);

uintmax_t			hex_cast_init(t_flag *flag, uintmax_t arg);
long long			di_cast_init(t_flag *flag, long long arg);
uintmax_t			ou_cast_init(t_flag *flag, uintmax_t arg);

void				prc_buff(t_flag *flag);

void				cero(t_flag *flag);

void				scalpel(t_flag *flag, int what);
void				greffe(t_flag *flag);

int					unicode(t_flag *flag, wchar_t c, int k);
void				uni_str(t_flag *flag, wchar_t *c);
void				uni_uni(t_flag *flag, wchar_t *str);
void				castedwide(int n, t_flag *flag, wchar_t c);
void				wide(int n, t_flag *flag, char *tab);
int					size(wchar_t c);

void				type_uint(uintmax_t nb, t_flag *flag, int base);
void				ft_u_prc(char *str, t_flag *flag);
void				ft_u_lrg(char *str, t_flag *flag);

void				modulo(t_flag *flag);

void				hex(t_flag *flag, uintmax_t nb);

#endif

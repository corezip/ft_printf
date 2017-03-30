/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:03:57 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/15 15:03:59 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <locale.h>
# include <wchar.h>
# include "./libft/libft.h"

typedef	struct			s_pres
{
	int				space;
	int				presition;
	int				i;
	char			str[100];
}						t_pres;

typedef	struct			s_main
{
	int				count;
	int				len;
	char			*format;
}						t_main;

typedef	struct			s_u
{
	unsigned int	value;
	int				count;
	int				flag;
	long int		i;
}						t_u;

typedef	struct			s_d
{
	int				value;
	int				count;
	int				flag;
	int				len;
	char			*str;
}						t_d;

typedef	struct			s_s
{
	char			*value;
	int				len;
	int				count;
}						t_s;

typedef	struct			s_o
{
	int				remainder;
	int				octal;
	int				i;
	int				n;
	int				x;
}						t_o;

typedef	struct			s_x
{
	long int		decimalnumber;
	long int		remainder;
	long int		quotient;
	int				i;
	int				count;
	int				value;
	int				temp;
	char			hexadecimalnumber[100];
	char			*hexa;
}						t_x;

typedef	struct			s_zero
{
	int				ilen;
	char			convert[20];
	char			*tmp;
	int				num;
}						t_zero;

typedef	struct			s_head
{
	t_d				head_d;
	t_s				head_s;
	t_o				head_o;
	t_x				head_x;
	t_u				head_u;
	t_zero			head_zero;
	t_pres			head_pr;
}						t_head;

int						ft_printf(const char *fmt, ...);
int						print_s(va_list ap);
int						print_c(va_list ap);
int						print_d(va_list ap, int flag, int space);
int						print_o(va_list ap, int flag);
int						print_x(va_list ap);
int						print_x_upper(va_list ap);
int						print_p(va_list ap);
int						print_u(va_list ap);
int						print_m();
int						read_con(char **fmt, va_list ap, int space);
void					un_putnbr(unsigned int n);
char					*reverse_array(char *s);
char					*ft_strlowcase(char *str);
int						u_calc(long int n);
void					u_putnbr(unsigned int n);
int						resul_hex(t_head *x);
int						hash(char ***fmt, va_list ap);
int						zero_w(char ****fmt, va_list ap, int flag);
int						number_len(t_head *i);
int						mult_options(char ***fmt, va_list ap);
int						space_d(char ****fmt, va_list ap, int flag);
int						print_d_positive(t_head *x);
int						pre_d_s(t_head *x, va_list ap, int flag);
int						print_d_negative(t_head *x);
int						pre_s(t_head *x, va_list ap, int flag);

#endif

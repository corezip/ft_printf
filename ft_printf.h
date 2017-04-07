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
	int				calc;
	int				negative;
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

typedef	struct			s_ld
{
	long long		value;
	long long		count;
}						t_ld;

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
	t_ld			head_ll;
}						t_head;

int						ft_printf(const char *fmt, ...);
int						print_s(char *s);
int						print_c(va_list ap);
int						print_d(va_list ap, int flag, int space);
int						print_o(va_list ap, int flag);
int						print_x(va_list ap);
int						print_x_upper(va_list ap);
int						print_p(va_list ap);
int						print_u(va_list ap);
int						print_m();
int						read_con(char **fmt, va_list ap, int space);
int						extra_con(char ***fmt, va_list ap, int flag);
void					un_putnbr(unsigned int n);
char					*reverse_array(char *s);
char					*ft_strlowcase(char *str);
int						u_calc(long int n);
void					u_putnbr(unsigned int n);
int						resul_hex(t_head *x);
int						hash(char ***fmt, va_list ap);
int						zero_w(char ****fmt, va_list ap, int flag);
int						dot_zer(char *****fmt, va_list ap, t_head *z, int flag);
int						number_len(t_head *i);
int						mult_options(char ***fmt, va_list ap);
int						space_d(char ****fmt, va_list ap, int flag, int i);
int						print_d_positive(t_head *x);
int						pre_d_s(t_head *x, va_list ap, int flag);
int						print_d_negative(t_head *x);
int						pre_s(t_head *x, va_list ap, int flag);
int						values_presition(char *****fmt, va_list ap,
	t_head *x, int flag);
int						equal_less_d(int value, t_head *x, int flag, int count);
int						plus_d(int value, t_head *x, int flag, int count);
int						extra_d(int value, t_head *x, int flag, int count);
int						s_values(char *s, t_head *x, int flag, int negative);
int						second_option(char *s, t_head *x);
char					*ft_itoa_base(int value, int base);
int						ft_digitnum(int n, int base);
int						l_funtion(char ****fmt, va_list ap);
int						ll_funtion(char *****fmt, va_list ap);
int						ll_d(long long n);
int						ft_lputnbr(long long n);
int						print_l_c(wint_t w);
char					*ft_l_itoa_base(unsigned long long int value, int base);
int						ll_uns(unsigned long long int x, int flag, int z);
int						print_s_negative(t_head *x);
int						print_s_positive(t_head *x);

#endif

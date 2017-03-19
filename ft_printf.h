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

typedef	struct			s_d
{
	int			precision;
	int			width;
	int			value;
	int			count;
	int			flag;
}						t_d;

typedef	struct			s_s
{
	int			precision;
	int			width;
	char		*value;
}						t_s;

typedef	struct			s_o
{
	int			remainder;
	int			octal;
	int			i;
	int			n;
	int			x;
}						t_o;

typedef	struct			s_x
{
	long int	decimalnumber;
	long int	remainder;
	long int	quotient;
	int			i;
	int			count;
	int			value;
	int			temp;
	char		hexadecimalnumber[100];
	char		*hexa;
}						t_x;

typedef	struct			s_head
{
	t_d			head_d;
	t_s			head_s;
	t_o			head_o;
	t_x			head_x;
}						t_head;

int						ft_printf(const char *fmt, ...);
int						print_s(va_list ap);
int						print_c(va_list ap);
int						print_d(va_list ap);
int						print_o(va_list ap);
int						print_x(va_list ap);
int						print_x_upper(va_list ap);
int						print_p(va_list ap);
int						print_m();
char					*reverse_array(char *s);
char					*ft_strlowcase(char *str);

#endif

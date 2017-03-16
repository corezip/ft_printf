/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:37:43 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 21:37:44 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_o(va_list ap)
{
	int remainder;
	int octal;
	int i;
	int n;

	i = 1;
	octal = 1;
	n = va_arg(ap, int);
	while (n != 0)
	{
		remainder = n % 8;
		n = n / 8;
		octal = octal + (remainder * i);
		i = i * 10;
	}
	octal -= 1;
	ft_putnbr(octal);
	return (1);
}

int			print_s(va_list ap)
{
	t_head *s;

	s = (t_head*)malloc(sizeof(t_head));
	s->head_s.value = va_arg(ap, char *);
	ft_putstr(s->head_s.value);
	return (1);
}

int			print_c(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int			print_d(va_list ap)
{
	t_head *i;

	i = (t_head*)malloc(sizeof(t_head));
	i->head_d.value = va_arg(ap, int);
	ft_putnbr(i->head_d.value);
	return (1);
}

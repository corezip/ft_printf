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

int				print_x(va_list ap)
{
	t_head		*x;
	int			count;

	count = 1;
	x = (t_head*)malloc(sizeof(t_head));
	x->head_x.decimalnumber = va_arg(ap, int);
	x->head_x.i = 0;
	x->head_x.quotient = x->head_x.decimalnumber;
	while (x->head_x.quotient != 0)
	{
		x->head_x.temp = x->head_x.quotient % 16;
		if (x->head_x.temp < 10)
			x->head_x.temp = x->head_x.temp + 48;
		else
			x->head_x.temp = x->head_x.temp + 55;
		x->head_x.hexadecimalnumber[x->head_x.i++] = x->head_x.temp;
		x->head_x.quotient = x->head_x.quotient / 16;
		count++;
	}
	reverse_array(x->head_x.hexadecimalnumber);
	ft_strlowcase(x->head_x.hexadecimalnumber);
	ft_putstr(x->head_x.hexadecimalnumber);
	return (count);
}

int				print_o(va_list ap)
{
	t_head		*o;

	o = (t_head*)malloc(sizeof(t_head));
	o->head_o.i = 1;
	o->head_o.octal = 1;
	o->head_o.n = va_arg(ap, int);
	o->head_o.x = o->head_o.n;
	while (o->head_o.n != 0)
	{
		o->head_o.remainder = o->head_o.n % 8;
		o->head_o.n = o->head_o.n / 8;
		o->head_o.octal = o->head_o.octal + (o->head_o.remainder * o->head_o.i);
		o->head_o.i = o->head_o.i * 10;
	}
	ft_putnbr(o->head_o.octal - 1);
	o->head_o.i = 1;
	while (o->head_o.x / 10 > 0)
	{
		o->head_o.x = o->head_o.x / 10;
		o->head_o.i++;
	}
	return (o->head_o.i);
}

int				print_s(va_list ap)
{
	t_head		*s;
	int			i;

	s = (t_head*)malloc(sizeof(t_head));
	s->head_s.value = va_arg(ap, char *);
	ft_putstr(s->head_s.value);
	i = ft_strlen(s->head_s.value);
	return (i);
}

int				print_c(va_list ap)
{
	char		c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int				print_d(va_list ap)
{
	t_head		*i;

	i = (t_head*)malloc(sizeof(t_head));
	i->head_d.value = va_arg(ap, int);
	ft_putnbr(i->head_d.value);
	i->head_d.count = 1;
	i->head_d.flag = 0;
	if (i->head_d.value < 0)
	{
		i->head_d.flag = 1;
		i->head_d.count++;
	}
	while ((i->head_d.value / 10 < 0 && (i->head_d.flag == 1)) ||
	(i->head_d.value / 10 > 0 && i->head_d.flag == 0))
	{
		i->head_d.value = i->head_d.value / 10;
		i->head_d.count++;
	}
	return (i->head_d.count);
}

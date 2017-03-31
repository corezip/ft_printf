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

int				number_len(t_head *i)
{
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

int				print_o(va_list ap, int flag)
{
	t_head		*o;

	o = (t_head*)malloc(sizeof(t_head));
	o->head_o.i = 1;
	o->head_o.octal = 1;
	o->head_o.n = va_arg(ap, int);
	if (o->head_o.n == 0 && flag == 1)
		return (1);
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
	if (s->head_s.value == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
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

int				print_d(va_list ap, int flag, int space)
{
	t_head		*i;

	i = (t_head*)malloc(sizeof(t_head));
	i->head_d.value = va_arg(ap, int);
	if (space == 1 && i->head_d.value > 0)
		write (1, " ", 1);
	if (i->head_d.value >= 0 && flag == 1)
	{
		write(1, "+", 1);
		ft_putnbr(i->head_d.value);
		return (number_len(i) + 1);
	}
	ft_putnbr(i->head_d.value);
	return (number_len(i) + space);
}

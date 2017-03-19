/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:29:47 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/17 19:29:49 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_x_upper(va_list ap)
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
	ft_putstr(x->head_x.hexadecimalnumber);
	return (count);
}

int				print_p(va_list ap)
{
	int			i;

	write(1, "0x7fff", 6);
	i = print_x(ap);
	return (i);
}

int				print_m(void)
{
	write(1, "%", 1);
	return (1);
}

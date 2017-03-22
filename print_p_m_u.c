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

int				print_u(va_list ap)
{
	t_head		*i;

	i = (t_head*)malloc(sizeof(t_head));
	i->head_u.value = (unsigned int)va_arg(ap, int);
	u_putnbr(i->head_u.value);
	i->head_u.count = 1;
	i->head_u.flag = 0;
	while (i->head_u.flag == 1 || (i->head_u.value / 10 > 0 && i->head_u.flag
		== 0))
	{
		i->head_u.value = i->head_u.value / 10;
		i->head_u.count++;
	}
	return (i->head_u.count);
}

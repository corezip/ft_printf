/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:52:51 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/22 16:52:53 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			choose_zero(char ****fmt, va_list ap, t_head *z)
{
	z->head_d.count = 0;
	if (****fmt == 'd')
		{
			z->head_d.value = va_arg(ap, int);
			z->head_d.str = ft_itoa(z->head_d.value);
			z->head_d.flag = ft_strlen(z->head_d.str);
			if( z->head_zero.ilen < z->head_d.flag)
			{
				z->head_zero.ilen = z->head_d.flag - z->head_zero.ilen;
				while (++z->head_d.count != z->head_zero.ilen)
					write(1,"0",1);
				ft_putnbr(z->head_d.value);
				return (z->head_zero.ilen +
					(ft_strlen(ft_itoa(z->head_d.value))));
			}
		}
	return (0);
}

int			zero_w(char ****fmt, va_list ap)
{
	t_head	*z;

	***fmt += 1;
	z = (t_head*)malloc(sizeof(t_head));
	z->head_zero.ilen = 0;
	while (****fmt >= '0' && ****fmt <= '9')
	{
		z->head_zero.convert[z->head_zero.ilen] = ****fmt + 0;
		***fmt += 1;
		z->head_zero.ilen++;
	}
	z->head_zero.num = ft_atoi(z->head_zero.convert);
	// printf("%d\n", z->head_zero.num);
	return (choose_zero(fmt, ap, z));
}

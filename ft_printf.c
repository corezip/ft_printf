/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:37:31 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 14:37:33 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_con(char *fmt, va_list ap)
{
	if (*fmt == 's' || *fmt == 'S')
		return (print_s(ap));
	else if (*fmt == 'i' || *fmt == 'd')
		return (print_d(ap));
	else if (*fmt == 'o' || *fmt == 'O')
		return (print_o(ap));
	else if (*fmt == 'c' || *fmt == 'C')
		return (print_c(ap));
	else if (*fmt == 'x')
		return (print_x(ap));
	else if (*fmt == 'X')
		return (print_x_upper(ap));
	else if (*fmt == 'p')
		return (print_p(ap));
	else if (*fmt == '%')
		return (print_m());
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			count;
	int			len;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			if ((len = read_con((char *)fmt, ap)) == 0)
				break ;
			count += len;
		}
		else
		{
			ft_putchar(*fmt);
			count += 1;
		}
		fmt += 1;
	}
	va_end(ap);
	return (count);
}

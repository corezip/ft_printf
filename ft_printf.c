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

int			read_con(const char *fmt, va_list ap)
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
	else if (*fmt == 'u' || *fmt == 'U')
		return (print_u(ap));
	else if (*fmt == '%')
		return (print_m());
	// else if (*fmt >= '0' && *fmt >= '9')
	// 	return ();

	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_main		x;

	x.count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt += 1;
			while (*fmt == ' ')
				fmt += 1;
			if ((x.len = read_con(&fmt, ap)) == 0)
				break ;
			x.count += x.len;
		}
		else
		{
			ft_putchar(*fmt);
			x.count += 1;
		}
		fmt += 1;
	}
	va_end(ap);
	return (x.count);
}

int			main(void)
{
	char s[10] = "hola";
	ft_printf("ft: %c\n", 65);
	printf("Or: %c\n", 65);
	return (1);
}

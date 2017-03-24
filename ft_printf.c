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

int			hash(char ***fmt, va_list ap)
{
	**fmt += 1;
	while (***fmt == ' ')
		**fmt += 1;
	if (***fmt == 'o' || ***fmt == 'O')
	{
		write(1, "0", 1);
		return ((print_o(ap)) + 1);
	}
	else if (***fmt == 'x')
	{
		write(1, "0x", 2);
		return ((print_x(ap)) + 2);
	}
	else if (***fmt == 'X')
	{
		write(1, "0X", 2);
		return ((print_x_upper(ap)) + 2);
	}
	return (0);
}

int			extra_con(char ***fmt, va_list ap)
{
	if (***fmt >= '0')
		return (zero_w(&fmt, ap));
	else if (***fmt >= '1' && ***fmt >= '9')
		return (0);
	return (0);
}

int			read_con(char **fmt, va_list ap)
{
	if (**fmt == 's' || **fmt == 'S')
		return (print_s(ap));
	else if (**fmt == 'i' || **fmt == 'd')
		return (print_d(ap));
	else if (**fmt == 'o' || **fmt == 'O')
		return (print_o(ap));
	else if (**fmt == 'c' || **fmt == 'C')
		return (print_c(ap));
	else if (**fmt == 'x')
		return (print_x(ap));
	else if (**fmt == 'X')
		return (print_x_upper(ap));
	else if (**fmt == 'p')
		return (print_p(ap));
	else if (**fmt == 'u' || **fmt == 'U')
		return (print_u(ap));
	else if (**fmt == '%')
		return (print_m());
	else if (**fmt == '#')
		return (hash(&fmt, ap));
	else
		return (extra_con(&fmt, ap));
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_main		x;

	x.count = 0;
	va_start(ap, fmt);
	x.format = (char*) fmt;
	while (*x.format)
	{
		if (*x.format == '%')
		{
			x.format += 1;
			while (*x.format == ' ')
				x.format += 1;
			if ((x.len = read_con(&x.format, ap)) == 0)
				break ;
			x.count += x.len;
		}
		else
		{
			ft_putchar(*x.format);
			x.count += 1;
		}
		x.format += 1;
	}
	va_end(ap);
	return (x.count);
}

int			main(void)
{
	char s[10] = "hola";
	ft_printf("ft: %09d\n", 5656);
	printf("Or: %09d\n", 5656);
	return (1);
}

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

// int		inicializar(va_list pa, const char *fmt)
// {
// 	t_head	*start;

// 	start = (t_head*) malloc(sizeof(t_head));
// 	if ()
// 	start->head_s.precision = 0;
// 	start->head_s.width = 0;
// }

int			read_con(char *fmt, va_list ap)
{
	if (*fmt == 's')
		return (print_s(ap));
	else if (*fmt == 'i' || *fmt == 'd')
		return (print_d(ap));
	else if (*fmt == 'o')
		return (print_o(ap));
	else if (*fmt == 'c')
		return (print_c(ap));
	// else if(*fmt == ".")
	// 		return (inicializar(va, fmt));
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			ret;
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
	return (0);
}

int			main(void)
{
	char s[15] = "como estas";
	printf("%s %s\n", s, "😗");
	ft_printf("%s %s\n", s,"😗");
	return (0);
}

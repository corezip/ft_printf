#include "ft_printf.h"

int				l_funtion(char ****fmt, va_list ap)
{
	***fmt += 1;
	if (****fmt == 'i' || ****fmt == 'd')
		return (ll_d(va_arg(ap, long long)));
	else if (****fmt == 'x')
		return (print_x(ap));
	else if (****fmt == 'X')
		return (print_x_upper(ap));
	else if (****fmt == 'l')
	{
		***fmt += 1;
		if (****fmt == 'i' || ****fmt == 'd')
			return (ll_d(va_arg(ap, long long)));
		else if (****fmt == 'x')
			return (print_x(ap));
		else if (****fmt == 'X')
			return (print_x_upper(ap));
		else if (****fmt == 'c' || ****fmt == 'C')
			return (wide_handle(va_arg(ap, wint_t)));
	}
	return (0);
}

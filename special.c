#include "ft_printf.h"

int				l_funtion(char ****fmt, va_list ap)
{
	***fmt += 1;
	if (****fmt == 'i' || ****fmt == 'd')
		return (ll_d(va_arg(ap, long long)));
	if (****fmt == 'l')
	{
		***fmt += 1;
		if (****fmt == 'i' || ****fmt == 'd')
			return (ll_d(va_arg(ap, long long)));
	}
	return (0);
}

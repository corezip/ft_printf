#include "ft_printf.h"

int				ll_uns(unsigned long long int x, int flag, int z)
{
	char *str;
	int i;

	str = ft_l_itoa_base(x, flag);
	if (z == 1)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = (str[i] - 32);
			}
			i++;
		}
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int				hh_funtion(char *****fmt, va_list ap)
{
	****fmt += 1;
	if (*****fmt == 'i' || *****fmt == 'd' || *****fmt == 'u' || *****fmt == 'D')
		return (ll_uns(va_arg(ap, unsigned long long int), 10, 0));
	else if (*****fmt == 'x')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 0));
	else if (*****fmt == 'X')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 1));
	else if (*****fmt == 'o')
		return (ll_uns(va_arg(ap, unsigned long long int), 8, 0));
	else if (*****fmt == 'c' || *****fmt == 'C')
			return (print_l_c(va_arg(ap, wint_t)));
		return (0);
}

int				l_funtion(char ****fmt, va_list ap)
{
	***fmt += 1;
	if (****fmt == 'i' || ****fmt == 'd' || ****fmt == 'u' || ****fmt == 'D')
		return (ll_uns(va_arg(ap, unsigned long long int), 10, 0));
	else if (****fmt == 'x')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 0));
	else if (****fmt == 'X')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 1));
	else if (****fmt == 'o')
		return (ll_uns(va_arg(ap, unsigned long long int), 8, 0));
	else if (****fmt == 'c' || ****fmt == 'C')
		return (print_l_c(va_arg(ap, wint_t)));
	else if (****fmt == 's' || ****fmt == 'S')
		return (print_s(va_arg(ap, char*)));
	else if (****fmt == 'l')
	{
		***fmt += 1;
		if (****fmt == 'i' || ****fmt == 'd' || ****fmt == 'u')
			return (ll_uns(va_arg(ap, unsigned long long int), 10, 0));
		else if (****fmt == 'x')
			return (ll_uns(va_arg(ap, unsigned long long int), 6, 0));
		else if (****fmt == 'X')
			return (ll_uns(va_arg(ap, unsigned long long int), 6, 1));
		else if (****fmt == 'o')
			return (ll_uns(va_arg(ap, unsigned long long int), 8, 0));
	}
	else if (****fmt == 'h')
		return (hh_funtion(&fmt, ap));
	return (0);
}
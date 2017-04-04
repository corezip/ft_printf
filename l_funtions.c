#include "ft_printf.h"

int				ft_lputnbr(long long n)
{
	int x;

	x = 0;
	if (n == -9223372036854775807)
		ft_putstr("-9223372036854775807");
	if (n < 0 && n > -9223372036854775807)
	{
		ft_putchar('-');
		n *= -1;
		x += 1;
	}
	if (n < 10 && n > -9223372036854775807)
		ft_putchar(n + 48);
	else if (n >= 10)
	{
		x += 1;
		ft_lputnbr(n / 10);
		ft_lputnbr(n % 10);
	}
	return (n);
}

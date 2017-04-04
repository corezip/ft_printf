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

char			*wide_to_string(wint_t w)
{
	char *p;

	p = ft_strnew(4);
	if (w <= 0x0ff)
		p[0] = w;
	else if (w <= 0x07ff)
	{
		p[0] = (w >> 6) + 0xc0;
		p[1] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0xFFFF)
	{
		p[0] = (w >> 12) + 0xe0;
		p[1] = ((w >> 6) & 0x3f) + 0x80;
		p[2] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0x10FFFF)
	{
		p[0] = (w >> 18) + 0xf0;
		p[1] = (w >> 12 & 0x3f) + 0x80;
		p[2] = (w >> 6 & 0x3f) + 0x80;
		p[3] = (w & 0x3f) + 0xc80;
	}
	return (p);
}

int				wide_handle(wint_t w)
{
	char *s;

	s = wide_to_string(w);
	if (w == 0)
		write(1, "0", 1);
	else
		ft_putstr(s);
	ft_strdel(&s);
	return (1);
}

#include "ft_printf.h"

int				plus_d(int value, t_head *x, int flag, int count)
{
	return (0);
}

int				equal_less_d(int value, t_head *x, int flag, int count)
{
	int calc;

	calc = ft_strlen(ft_itoa(value));
	if (calc >= x->head_pr.presition)
	{
		ft_putnbr(value);
		return (calc);
	}
	else if (calc < x->head_pr.presition)
	{
		calc = x->head_pr.presition - calc;
		if (calc < 0)
			calc = (calc * -1) - 1;
		while(count != calc)
		{
			write(1, "0", 1);
			count += 1;
		}
		ft_putnbr(value);
		return (calc + x->head_d.len + 1);
	}
	return (0);
}

//x->head_pr.space tiene el valor del primer entero detras del punto.
//X = x->head_pr.space
//Y = x->head_pr.presition
int				values_presition(char *****fmt, va_list ap, t_head *x, int flag)
{
	****fmt += 1;
	x->head_pr.i = 0;
	ft_bzero(x->head_pr.str, 99);
	while (*****fmt >= '0' && *****fmt <= '9')
	{
		x->head_pr.str[x->head_pr.i++] = *****fmt + 0;
		****fmt += 1;
	}
	x->head_pr.presition = ft_atoi(x->head_pr.str);
	if (*****fmt == 'd')
	{
		if (x->head_pr.space <= x->head_pr.presition)
			return (equal_less_d(va_arg(ap, int), x, flag, 0));
		else if (x->head_pr.space > x->head_pr.presition)
			return (plus_d(value, t_head, flag, count));
	}
	return (0);
}

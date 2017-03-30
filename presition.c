#include "ft_printf.h"

int				equal_less_d(int value, t_head *x, int flag, int count)
{
	if (value <= x->head_pr.presition)
	{
		x->head_d.str = ft_itoa(value);
		x->head_d.len = ft_strlen(x->head_d.str);
		ft_putnbr(value);
		return (x->head_d.len);
	}
	else if (value > x->head_pr.presition)
	{
		x->head_d.str = ft_itoa(value);
		x->head_d.len = ft_strlen(x->head_d.str);
		int y = x->head_pr.presition;
		int len = x->head_d.len;
		while(count != (y - len))
		{
			write(1, "0", 1);
			count += 1;
		}
		ft_putnbr(value);
		return (x->head_pr.presition);
	}
	return (flag);
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
	// printf("|%d|.|%d|\n", x->head_pr.space, x->head_pr.presition);
	if (*****fmt == 'd')
	{
		if (x->head_pr.space <= x->head_pr.presition)
			return (equal_less_d(va_arg(ap, int), x, flag, 0));//primera en hacer.
		else if (x->head_pr.space > x->head_pr.presition)
			return (0);
	}
	return (0);
}

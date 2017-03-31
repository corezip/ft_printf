
#include "ft_printf.h"
int				extra_d(int value, t_head *x, int flag, int count)
{
	//x->head_pr.calc -- longitud del argumento
	flag = 1;
	x->head_pr.space = x->head_pr.space - x->head_pr.presition;
	while (count != x->head_pr.space)
	{
		write(1, " ", 1);
		count += 1;
	}
	x->head_pr.presition = x->head_pr.presition - x->head_pr.calc;
	count = 0;
	while (count != x->head_pr.presition)
	{
		write(1, "0", 1);
		count += 1;
	}
	ft_putnbr(value);
	return (x->head_pr.space + x->head_pr.presition + x->head_pr.calc);
}

/*
**       Esta funcion seleccionara el rumbo del la impresion dado sus casos.
*/

int				plus_d(int value, t_head *x, int flag, int count)
{
	flag = 1;
	x->head_pr.calc = ft_strlen(ft_itoa(value));
	if (x->head_pr.calc >= x->head_pr.space)
	{
		ft_putnbr(value);
		return (x->head_pr.calc);
	}
	else if (x->head_pr.calc < x->head_pr.space && x->head_pr.calc >=
		x->head_pr.presition)
	{
		x->head_pr.calc = x->head_pr.space - x->head_pr.calc;
		if (x->head_pr.calc < 0)
			x->head_pr.calc = (x->head_pr.calc * -1) - 1;
		while(count != x->head_pr.calc)
		{
			write(1, " ", 1);
			count += 1;
		}
		ft_putnbr(value);
		return (x->head_d.len + x->head_pr.space);
	}
	else
		return (extra_d(value, x, flag, count));
}

int				equal_less_d(int value, t_head *x, int flag, int count)
{
	flag = 1;
	x->head_pr.calc = ft_strlen(ft_itoa(value));
	if (x->head_pr.calc >= x->head_pr.presition)
	{
		ft_putnbr(value);
		return (x->head_pr.calc);
	}
	else if (x->head_pr.calc < x->head_pr.presition)
	{
		x->head_pr.calc = x->head_pr.presition - x->head_pr.calc;
		if (x->head_pr.calc < 0)
			x->head_pr.calc = (x->head_pr.calc * -1) - 1;
		while(count != x->head_pr.calc)
		{
			write(1, "0", 1);
			count += 1;
		}
		ft_putnbr(value);
		return (x->head_d.len + x->head_pr.presition);
	}
	return (0);
}

/*
**        x->head_pr.space tiene el valor del primer entero detras del punto.
**        X = x->head_pr.space
**        Y = x->head_pr.presition
*/
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
			return (plus_d(va_arg(ap, int), x, flag, 0));
	}
	return (0);
}

#include "ft_printf.h"

int			main(void)
{
	char s[100] = "alkfjhalkjsdfhlkajshdflkjahsldkjfhalksjdhflkajhsdflkjhalskdj";
	// printf("OR: |%x\n", 56158455656);
	// ft_printf("FT: |%x\n", 56158455656);
	printf("OR: |%p\n", s);
	ft_printf("FT: |%p\n", s);
	return (0);
}

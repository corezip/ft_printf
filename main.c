#include "ft_printf.h"

int			main(void)
{
	char s[100] = "alkfjhalkjsdfhlkajshdflkjahsldkjfhalksjdhflkajhsdflkjhalskdj";
	printf("OR: |%X\n", -15656546546);
	ft_printf("FT: |%X\n", -15656546546);
	// printf("OR: |%p\n", s);  6565654654654
	// ft_printf("FT: |%p\n", s);
	return (0);
}

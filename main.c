#include "ft_printf.h"

int			main(void)
{
	char s[19] = "hola pepe";
	printf("cantidad FT: %d\n", ft_printf("FT: |%+04d\n", 42));
	printf("cantidad OR: %d\n", printf("Or: |%+04d\n", 42));
	ft_printf("FT: |%o\n", 17500);
	printf("OR: |%o\n", 17500);
	return (1);
}

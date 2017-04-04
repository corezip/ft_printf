#include "ft_printf.h"

int			main(void)
{
	// char s[19] = "hola pepe";
	// printf("cantidad FT: %d\n", ft_printf("FT: |%+04d\n", 42));
	// printf("cantidad OR: %d\n", printf("Or: |%+04d\n", 42));
	ft_printf("FT: |%lld\n", 175564546500);
	printf("OR: |%lld\n", 175564546500);
	return (1);
}

#include "ft_printf.h"

int			main(void)
{
	// wchar_t *s = "hola pepe";
	// printf("cantidad FT: %d\n", ft_printf("FT: |%+04d\n", 42));
	// printf("cantidad OR: %d\n", printf("Or: |%+04d\n", 42));
	ft_printf("FT: |%lo\n", 5656498165);
	printf("OR: |%lo\n", 5656498165);
	return (1);
}

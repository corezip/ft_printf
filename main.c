#include "ft_printf.h"

int			main(void)
{
	char s[10] = "hola pepe";
	printf("cantidad FT: %d\n", ft_printf("FT: |%+04d\n", 42));
	printf("cantidad OR: %d\n", printf("Or: |%+04d\n", 42));
	// ft_printf("FT: |%p\n", "sdfgsdfgsdfgsdasdfasdfasdfasdfasdffgsdfgwesfgs");
	// printf("OR: |%p\n", "sdfgsdfgsdfgsdasdfasdfasdfasdfasdffgsdfgwesfgs");
	// printf("*****************\n");
	// ft_printf("FT:lo |%lo\n", 5656498165);
	// printf("OR:lo |%lo\n", 5656498165);
	// printf("*****************\n");
	// ft_printf("FT:lu |%lu\n", 5656498165);
	// printf("OR:lu |%lu\n", 5656498165);
	// printf("*****************\n");
	// ft_printf("FT:lx |%lx\n", 5656498165);
	// printf("OR:lx |%lx\n", 5656498165);
	// printf("*****************\n");
	// ft_printf("FT:lX |%lX\n", 5656498165);
	// printf("OR:lX |%lX\n", 5656498165);
	return (1);
}

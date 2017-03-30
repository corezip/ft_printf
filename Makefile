NAME = libftprintf.a

CFLAG = -c -Wall -Werror -Wextra

SRCS = ft_printf.c print_s_d_o.c print_p_m_u.c helper.c xnumber.c zero.c space.c\
presition.c

OBJS = $(SRCS:.c=.o)

LIB_OBJS = libft/*.o

RM = rm -f

LIBS = ./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS):
	@gcc $(CFLAG) $(SRCS)

$(LIB_OBJS):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIB_OBJS)
	@ar rcs $(NAME) $(LIB_OBJS) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mFT_PRINTF: Built library. ~(˘▾˘~) \033[0m"

clean:
	@/bin/rm -f $(OBJS)
	@$(MAKE) -C ./libft/ clean
	@echo "\033[32mFT_PRINTF: Cleaned up object files. ~(˘▾˘~) \033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C ./libft/ fclean
	@echo "\033[32mFT_PRINTF: Cleaned up compiled files. ~(˘▾˘~) \033[0m"

re: fclean all

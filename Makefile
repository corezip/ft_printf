NAME = libftprintf.a

CFLAG = -c -Wall -Werror -Wextra

SRCS = ft_printf.c print_s_d_o.c print_p_m_u.c helper.c xnumber.c zero.c space.c\
presition.c

OBJS = $(SRCS:.c=.o)

LIB_OBJS = libft/*.c

RM = rm -f

LIBS = ./libft/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS):
	gcc $(CFLAG) $(SRCS)

$(LIB_OBJS):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rcs $(NAME) $(LIB_OBJS) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)
	$(MAKE) -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all

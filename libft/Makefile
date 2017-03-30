# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsolis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 22:12:49 by gsolis            #+#    #+#              #
#    Updated: 2017/01/05 22:12:51 by gsolis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	*.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $? $(SRC)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLibft: Built library. ᕙ(⇀‸↼‶)ᕗ\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[32mLibft: Cleaned up object files. ᕙ(⇀‸↼‶)ᕗ\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mLibft: Cleaned up compiled files. ᕙ(⇀‸↼‶)ᕗ\033[0m"

re: fclean all

.PHONY: all clean fclean re

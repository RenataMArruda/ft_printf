# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rarruda <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/05 17:35:56 by rarruda       #+#    #+#                  #
#    Updated: 2021/10/11 10:46:33 by rarruda       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
		srcs/ft_conversions.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft 
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make clean -C libft
	rm -f *.o
	rm -f srcs/ft_conversions.o

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

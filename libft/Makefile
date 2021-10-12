# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rarruda <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/05 17:36:02 by rarruda       #+#    #+#                  #
#    Updated: 2021/10/08 10:46:48 by rarruda       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC =	ft_power.c\
	ft_putchar.c\
	ft_puthex.c\
	ft_putnbr.c\
	ft_putpoi.c\
	ft_putstr.c\
	ft_putunsnbr.c
	
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

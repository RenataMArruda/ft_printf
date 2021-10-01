NAME = libftprintf.a

SRC = ft_printf.c\
      libft/ft_power.c\
      libft/ft_putchar.c\
      libft/ft_puthex.c\
      libft/ft_putnbr.c\
      libft/ft_putpoi.c\
      libft/ft_putstr.c\
      libft/ft_putunsnbr.c

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

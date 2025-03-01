NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_putstr.c ft_putchr.c ft_putnbr.c ft_putunbr.c ft_putnbr_base.c ft_print_address.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)  
.PHONY: all clean fclean re

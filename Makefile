NAME = so_long

BNS_NAME = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

SRC = main.c helper_files/check_file_name.c get_next_line_/get_next_line.c get_next_line_/get_next_line_utils.c \
	check_map.c helper_files/clean.c helper_files/ft_strlen.c helper_files/flood_fill.c window.c helper_files/image_to_ptr.c\
	helper_files/check_walls.c helper_files/draw_map.c \

BNS_SRC = bonus_files/main_bonus.c bonus_files/helper_files/check_file_name.c \
	get_next_line_/get_next_line.c get_next_line_/get_next_line_utils.c \
	bonus_files/check_map.c bonus_files/helper_files/clean.c bonus_files/helper_files/helper_fun.c \
	bonus_files/helper_files/flood_fill.c bonus_files/window.c bonus_files/helper_files/image_to_ptr.c\
	bonus_files/helper_files/check_walls.c bonus_files/helper_files/draw_map.c bonus_files/helper_files/print_moves_bonus.c \
	bonus_files/helper_files/itoa.c bonus_files/animation.c bonus_files/helper_files/press_key.c\

OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS_SRC:.c=.o)

libmlx = minilibx-linux/libmlx_Linux.a

PRINTF_DIR = printf/libftprintf.a

$(NAME): $(OBJ) $(PRINTF_DIR)
	$(CC) $(OBJ) -o $(NAME) $(libmlx) -lXext -lX11 printf/libftprintf.a

$(PRINTF_DIR):
	@$(MAKE) -C printf
 

all : $(NAME) $(PRINTF_DIR)

bonus: $(BNS_NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(BNS_NAME): $(BNS_OBJ) $(PRINTF_DIR)
	$(CC) $(BNS_OBJ) -o $(BNS_NAME) $(libmlx) -lXext -lX11 printf/libftprintf.a

clean:
	$(RM) $(OBJ) $(BNS_OBJ)
	@$(MAKE) -C printf clean

fclean: clean
	$(RM) $(NAME) $(BNS_NAME)
	@$(MAKE) -C printf fclean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ) $(BNS_OBJ)

CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= so_long
OBJ_C= draw.c ft_itoa.c so_long.c ft_strncmp.c game.c ../check_map/check.c ../check_map/get_next_line.c ../check_map/get_next_line_utils.c ../check_map/ft_split.c ../check_map/ft_substr.c ../check_map/complete_siege.c animation.c ../ft_printf/ft_print_base.c ../ft_printf/ft_printf.c ../ft_printf/ft_putchar.c ../ft_printf/ft_putnbr.c ../ft_printf/ft_putstr.c ../ft_printf/ft_unsigned_decimal.c
OBJ_O= $(OBJ_C:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ_O)

fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
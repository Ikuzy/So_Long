NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 #-fsanitize=address 

SRC = parce_0.c so_long.c ft_split.c GNL/get_next_line_utils.c\
	 GNL/get_next_line.c mlx_fct.c player_movement.c floodfill.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./MLX/libmlx.a  -L/usr/lib -lX11 -lXext -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.SECONDARY: $(OBJ)
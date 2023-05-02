NAME = so_long
SRCS = src/main.c src/check.c src/imgs.c src/utils_map.c src/utils.c \
		src/memory_utils.c
LIBFT = libft/libft.a
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
MLX_FLAGS = -lmlx -Lmlx -lXext -lX11
#-framework OpenGl -framework Appkit
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(MLX) -o $(NAME)
$(LIBFT):
	make -C libft
$(MLX):
	make -C ./mlx
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
fclean_libft:
	make fclean -C ./libft
re: fclean all

.PHONY: all clean fclean re fclean_libft
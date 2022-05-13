NAME = try
CC = gcc
MLX = mlx/libmlx.a -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
SRCS = round.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
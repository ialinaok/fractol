NAME = try
CC = gcc
MLX = libmlx.a -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror
SRCS = hello_bye.c \
		pixel_put.c \
		trgb_bitwise.c \
		trgb_char_int.c \
		

# srcs for main (shader funct)
# main.c\
# 		pixel_put.c\
# 		trgb_bitwise.c\
# 		trgb_char_int.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
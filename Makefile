# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 10:26:31 by apielasz          #+#    #+#              #
#    Updated: 2022/05/26 20:50:35 by apielasz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
MLX = includes/mlx/libmlx.a -framework OpenGL -framework AppKit
LIBFT = includes/libft/libft.a
PRINTF = includes/ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c \
		srcs/utils.c \
		srcs/window.c \
		srcs/math.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
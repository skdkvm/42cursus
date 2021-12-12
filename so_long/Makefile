# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 16:57:46 by seonggki          #+#    #+#              #
#    Updated: 2021/12/12 18:23:57 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	main.c \
		error.c \
		parsing.c \
		check.c \
		get_next_line.c \
		ft_utils.c \
		display.c \
		map.c \
		texture.c

SRCS_PATH = srcs/

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

FT = -L libft -lft

MLX = -lmlx -lm -framework OpenGL -framework Appkit

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT) $(MLX)

clean:
	$(RM) $(OBJS)
	make -C libft/ clean
	make -C mlx/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all
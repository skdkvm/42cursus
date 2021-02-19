# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 23:28:43 by seonggki          #+#    #+#              #
#    Updated: 2021/01/25 21:22:09 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

NAME = libftprintf.a

SRCS = print_char.c print_hex.c print_pointer.c print_int.c print_str.c pasing.c printf_func1.c printf_func2.c ft_printf.c
OBJS = print_char.o print_hex.o print_pointer.o print_int.o print_str.o pasing.o printf_func1.o printf_func2.o ft_printf.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(AR) cr $@ $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

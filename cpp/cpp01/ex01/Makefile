# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:30:50 by seonggki          #+#    #+#              #
#    Updated: 2022/01/24 17:33:54 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde

CC = clang++

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I Zombie.hpp

SRCS = Zombie.cpp \
		ZombieHorde.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
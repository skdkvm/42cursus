# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 15:42:41 by seonggki          #+#    #+#              #
#    Updated: 2022/01/24 17:32:08 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brainz

CC = clang++

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I Zombie.hpp

SRCS = newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 16:34:54 by seonggki          #+#    #+#              #
#    Updated: 2022/01/27 16:30:15 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang++ -Wall -Wextra -Werror -std=c++98
RM 			= rm -rf
NAME 		= ./megaphone
NAME_SHORT  = megaphone

SRCS_DIR 	= .
SRCS 		= megaphone.cpp

_OK			= [\033[32mOK\033[0m]

$(NAME)		: $(SRCS)
				@$(CC) $(SRCS) -o $(NAME)
				@echo "$(_OK) $(NAME_SHORT) complied"

clean		:

fclean		: clean
				@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
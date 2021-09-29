# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <tjdrlf0618@naver.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 19:21:38 by seonggki          #+#    #+#              #
#    Updated: 2021/09/29 19:21:42 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex.a
PROG	= pipex

SRCS 	= srcs/pipex.c srcs/utils.c srcs/process.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

SRCS_B	= srcs/pipex_bonus.c srcs/process_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= srcs/pipex_bonus.c

HEADER	= -I./includes/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

$(NAME):	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@cp libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS}
					@$(CC) $(NAME) ${MAIN} -o ${PROG}
					@echo "\033[32mPipex Compiled\n"

all: 		${NAME}

bonus:		${OBJS_B}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@cp libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS_B}
					@$(CC) $(NAME) ${MAIN_B} -o ${PROG}
					@echo "\033[32mPipex Compiled!\n"

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING!\n"

re:			fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re bonus party
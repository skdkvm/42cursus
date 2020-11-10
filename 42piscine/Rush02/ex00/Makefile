CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
SRC = ./src/checking.c \
	./src/change_word2.c \
	./src/change_word1.c \
	./src/edit_dict.c \
	./src/split_num.c \
	./src/main.c \
	./src/print_err.c \
	./src/str_func.c
OBJ = ${SRC:.c=.o}

.PHONY:all clean fclean re
all: ${NAME}

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm $(OBJ)

fclean:
	rm -f $(NAME)
	rm $(OBJ)

re: fclean all

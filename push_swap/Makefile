NAME_CH =	checker
LIB =		Libft
GNL =		get_next_line
CHECK_DIR =	src

CHECK_SRC =	./$(CHECK_DIR)/checker.c ./$(CHECK_DIR)/sa.c ./$(CHECK_DIR)/sb.c ./$(CHECK_DIR)/ss.c ./$(CHECK_DIR)/pa.c ./$(CHECK_DIR)/pb.c ./$(CHECK_DIR)/ra.c ./$(CHECK_DIR)/rb.c ./$(CHECK_DIR)/rr.c ./$(CHECK_DIR)/rra.c ./$(CHECK_DIR)/rrb.c ./$(CHECK_DIR)/rrr.c \
			./$(CHECK_DIR)/print_stack.c ./$(CHECK_DIR)/call_command.c ./$(CHECK_DIR)/check_descending.c ./$(CHECK_DIR)/check_argv.c

INC_DIR = ./
OBJ_CH = $(CHECK_SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I.
OPTIONS = -I$(INC_DIR) -I./Libft -I./get_next_line -lft -L./Libft -lget_next_line -L./get_next_line

all : $(LIB) $(GNL) $(NAME_CH)

$(LIB) : relib cleanlib

$(GNL) : regnl cleangnl

$(NAME_CH):  $(LIB) $(GNL) $(OBJ_CH)
					${CC} ${CFLAGS} -o ${NAME_CH} ${OPTIONS} ${OBJ_CH}

clean:    cleanlib cleangnl
					rm -rf $(OBJ_CH)

fclean:   clean fcleanlib fcleangnl
					rm -rf $(NAME_CH)

re: fclean all

relib:
	@$(MAKE) -C ./Libft re

cleanlib:
	@$(MAKE) -C ./Libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./Libft fclean

regnl:
	@$(MAKE) -C ./get_next_line re

cleangnl:
	@$(MAKE) -C ./get_next_line clean

fcleangnl: cleangnl
	@$(MAKE) -C ./get_next_line fclean

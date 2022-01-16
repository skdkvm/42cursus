CC			= clang++ -Wall -Wextra -Werror
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
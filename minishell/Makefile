NAME = minishell

HEAD = ./includes/parser
SRCS = ./parser/
SRCS2 = ./srcs/
SRCS3 = $(SRCS2)build_in/
GNL = ./get_next_line/
RL = -L/Users/$(USER)/.brew/Cellar/readline/8.1.1/lib/ -I/Users/$(USER)/.brew/Cellar/readline/8.1.1/include -lreadline
#RL = -L/usr/local/Cellar/readline/8.1.1/lib/ -I/usr/local/Cellar/readline/8.1.1/include -lreadline

CFLAGS = -Wall -Wextra -Werror

C_FILE =	$(SRCS)parser.c $(SRCS)parser_utils.c $(SRCS)preparser.c $(SRCS)quotes.c\
			$(SRCS)utils.c $(SRCS)utils2.c $(SRCS)dollar.c $(SRCS)dollar_utils.c\
			$(SRCS)preparser_redirect.c $(SRCS)shlvl.c $(SRCS)signal.c $(SRCS)redirect.c\
			$(GNL)get_next_line.c $(GNL)get_next_line_utils.c\
			./main.c\
			$(SRCS2)exec_command.c $(SRCS2)ft_split.c $(SRCS2)env_utils.c $(SRCS2)start_cmd.c\
			$(SRCS3)other_commands.c $(SRCS3)export.c $(SRCS3)echo.c $(SRCS3)cd.c $(SRCS2)pipe.c\
			$(SRCS3)exit.c $(SRCS2)error_and_free.c $(SRCS2)list.c $(SRCS2)check_func.c $(SRCS3)export_utils.c\
			$(SRCS2)rewrite_env.c $(SRCS3)export_write.c

O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft bonus
	gcc $(O_FILE) ./libft/libft.a $(RL) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)
	$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re

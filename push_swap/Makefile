NAME_CH	:=	checker
NAME_PS	:=	push_swap

D_SRC	:=	src/
D_CH	:=	$(D_SRC)checker/
D_PS	:=	$(D_SRC)push_swap/
D_OBJ	:=	obj/
D_INC	:=	include/
D_LIBFT	:=	lib/libft/
D_TEST	:=	$(addprefix $(D_SRC), test/)

LIBFT	:=	$(addprefix $(D_LIBFT), libft.a)

SRC		:=	$(addsuffix .c, \
			parse \
			stack \
			stack_element \
			get_index \
			instruction \
			is_sorted \
			)
CH_SRC	:=	$(addsuffix .c, \
			checker \
			operations \
			)
PS_SRC	:=	$(addsuffix .c, \
			push_swap \
			push_chunk_to_b \
			stack_a \
			stack_b \
			print_swap \
			print_string \
			)

SRCS	:=	$(addprefix $(D_SRC), $(SRC))
CH_SRCS	:=	$(addprefix $(D_CH), $(CH_SRC))
PS_SRCS	:=	$(addprefix $(D_PS), $(PS_SRC))

OBJS	:=	$(addprefix $(D_OBJ), $(SRC:.c=.o))
CH_OBJS	:=	$(addprefix $(D_OBJ), $(CH_SRC:.c=.o))
PS_OBJS	:=	$(addprefix $(D_OBJ), $(PS_SRC:.c=.o))

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
SANITIZE:=	-fsanitize=address -g

INC		:=	-I$(D_INC)
INC		+=	-I$(D_LIBFT)

LIB		:=	-L$(D_LIBFT)
LIB		+=	-lft

RM		:=	rm -f

GREEN	:=	\033[32m
YELLOW	:=	\033[33m
RESET	:=	\033[0m

all:		$(D_OBJ) $(LIBFT) $(NAME_CH) $(NAME_PS)

$(NAME_CH):		$(OBJS) $(CH_OBJS)
			@echo "$(YELLOW)Build $(RESET)$@"
			@$(CC) $(CFLAGS) $(INC) $(LIB) -o $@ $^

$(NAME_PS):		$(OBJS) $(PS_OBJS)
			@echo "$(YELLOW)Build $(RESET)$@"
			@$(CC) $(CFLAGS) $(INC) $(LIB) -o $@ $^

$(D_OBJ)%.o:	$(D_SRC)%.c
			@echo "$(GREEN)compiling :$(RESET)" $<
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(D_OBJ)%.o:	$(D_CH)%.c
			@echo "$(GREEN)compiling :$(RESET)" $<
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(D_OBJ)%.o:	$(D_PS)%.c
			@echo "$(GREEN)compiling :$(RESET)" $<
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(D_OBJ):
			@mkdir $(D_OBJ)

$(LIBFT):
			@$(MAKE) -sC $(D_LIBFT) all

clean:
			@echo "$(YELLOW)-   Deleting all object from $(NAME_CH)/$(NAME_PS)...$(RESET)"
			@$(RM) -r $(D_OBJ)
			@$(MAKE) -sC $(D_LIBFT) clean

fclean:		clean
			@echo "$(YELLOW)-   Deleting all excutable from $(NAME_CH)/$(NAME_PS)...$(RESET)"
			@$(RM) $(NAME_CH) $(NAME_PS)

re:			fclean all

# unit test
T_UTIL		:=	$(addprefix $(D_TEST), \
				assert \
				)
T_PARSE		:=	$(addprefix $(D_TEST), test_parse)
TS_PARSE	:=	$(addsuffix .c, $(T_PARSE) $(T_UTIL))
TO_PARSE	:=	$(addsuffix .o, $(T_PARSE) $(T_UTIL))

T_OP		:=	$(addprefix $(D_TEST), test_do_op)
TS_OP		:=	$(addsuffix .c, $(T_OP) $(T_UTIL))
TO_OP		:=	$(addsuffix .o, $(T_OP) $(T_UTIL))

T_NAME		=	$(T_PARSE)
T_NAME		+=	$(T_OP)

T_OBJS		=	$(TO_PARSE)
T_OBJS		+=	$(TO_OP)

test:	$(D_OBJ) $(LIBFT) $(T_NAME)
			@$(RM) $(T_NAME) $(T_OBJS)

$(D_TEST)%.o:	$(D_TEST)%.c
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(T_PARSE):	$(OBJS) $(TO_PARSE)
			@$(CC) $(CFLAGS) $(SANITIZE) $(INC) $(LIB) -o $@ $^
			@echo "\n$(GREEN)<$(notdir $@)>$(RESET)\n"
			@./$@

$(T_OP):	$(OBJS) $(D_OBJ)do_op.o $(TO_OP)
			@$(CC) $(CFLAGS) $(SANITIZE) $(INC) $(LIB) -o $@ $^
			@echo "\n$(GREEN)<$(notdir $@)>$(RESET)\n"
			@./$@

.PHONY:		all clean fclean re bonus test

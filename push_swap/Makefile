NAME_CH	:=	checker
NAME_PS	:=	push_swap

D_SRC	:=	src/
D_CH	:=	$(D_SRC)checker/
D_PS	:=	$(D_SRC)push_swap/
D_OBJ	:=	obj/
D_INC	:=	include/
D_LIBFT	:=	lib/libft/

LIBFT	:=	$(addprefix $(D_LIBFT), libft.a)

SRC		:=	$(addsuffix .c, \
			parse \
			stack \
			stack_element \
			get_index \
			instruction \
			)
CH_SRC	:=	$(addsuffix .c, \
			checker \
			operations \
			)
PS_SRC	:=	$(addsuffix .c, \
			push_swap \
			stack_a \
			stack_b \
			print_swap \
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

.PHONY:		all clean fclean re bonus test

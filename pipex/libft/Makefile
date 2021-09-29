NAME	=	libft.a

SRCS	=	$(addsuffix .c, ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
			ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strlcat ft_strchr \
			ft_strrchr ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit \
			ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_calloc \
			ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa \
			ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
			ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstdelone ft_lstclear \
			ft_lstsize ft_lstlast ft_lstiter ft_lstmap ft_lstsort \
			ft_string_util ft_utoa ft_ultoa_base ft_putstr \
			\
			get_next_line)

D_OBJS	=	obj/
OBJS	=	$(addprefix $(D_OBJS), $(SRCS:.c=.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	-I./
RM		=	rm -f

GREEN	=	\033[32m
YELLOW	=	\033[33m
RESET	=	\033[0m

all:		$(D_OBJS) $(NAME)

bonus:		all

$(NAME):	$(OBJS)
			@echo "$(YELLOW)Build $(RESET)$(NAME)"
			@ar rc  $(NAME) $(OBJS)

$(D_OBJS)%.o:	%.c
			@echo "$(GREEN)compiling :$(RESET)" $<
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(D_OBJS):
			@mkdir $(D_OBJS)

clean:
			@echo "$(YELLOW)-   Deleting all object from $(NAME)...$(RESET)"
			@$(RM) -r $(D_OBJS)

fclean:		clean
			@echo "$(YELLOW)-   Deleting all excutable from $(NAME)...$(RESET)"
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus

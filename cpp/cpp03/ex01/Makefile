NAME		=	ScavTrap
CP			=	clang++ -std=c++98
CPFLAGS		=	-Wall -Wextra -Werror

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp
				

RM			=	rm -rf

OBJ			=	$(SRC:.cpp=.o)

%.o			:	%.cpp
				$(CP) $(CPFLAGS) -c $< -o $@

$(NAME)		:	$(OBJ)
				$(CP) $(CPFLAGS) $(OBJ) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
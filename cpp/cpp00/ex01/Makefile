NAME = phonebook

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I phonebook.hpp -I contact.hpp

SRCS = phonebook.cpp \
		contact.cpp \
		main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 00:33:15 by seonggki          #+#    #+#              #
#    Updated: 2021/12/12 17:47:59 by seonggki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o

AR = ar
ARFLAGS = rc
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_atoi.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

SRCS_B = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lst_at.c \


OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS) $(SRCS_B)

$(NAME) : $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(NAME) $(OBJS_B)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_B)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

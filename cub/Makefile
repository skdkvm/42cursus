NAME = cub3D

SRCS = cub3d.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./util/err.c \
		./util/split.c \
		./value/read_file.c \
		./value/init_info.c \
		./value/put_info_one.c \
		./value/put_info_two.c \
		./value/put_map.c \
		./value/check_map.c \
		./logic/raycasting_base.c \
		./logic/raycasting_texture.c \
		./logic/sprite.c \
		./logic/key_press.c \
		./bmp.c

OBJS = $(SRCS:.c=.o)

RM = rm -f
LIB = ar rcu
CC = clang
CFLAGS = -Wall -Wextra -Werror
MLX = mlx
LXFLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make all -C ./libft
	cp ./libft/libft.a libft.a
	$(CC) -o $(NAME) $(CFLAGS) -L$(MLX) -l$(MLX) $(LXFLAGS) $(OBJS) libft.a

all : $(NAME)

clean :
	make clean -C ./libft
	$(RM) $(OBJS) libft.a

fclean : clean
	make fclean -C ./libft
	$(RM) $(NAME)

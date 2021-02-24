NAME = cub3d

CC = gcc
FLAGS = -Wall -Wextra -Werror
DY = libmlx.dylib
A = libmlx.a
# OBJS = $(SRCS:.c=.o)
SRCS = start.c

all: $(NAME)

# $(NAME) :
# 	# gcc $(DY) start.c -o $@
# 	gcc start.c -L. -lmlx -framework OpenGL -framework AppKit -lz -o $@
# 	./cub3d

$(NAME) :
	# make bonus -C ./libft
	# cp ./libft/libft.a .
	# make fclean -C ./libft
	gcc ./*.c ./get_next_line/*.c -L. -lft -I./libft -I./get_next_line -I. -fsanitize=address
	./a.out ./test.cub
	rm a.out
	# rm libft.a


clean:
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C $(MMS_DIR) clean
	$(MAKE) -C $(OPENGL_DIR) clean

re: fclean all


bonus: all
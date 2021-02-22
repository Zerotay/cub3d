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
	gcc ./*.c ./get_next_line/*.c -L. -lft -I./libft -I./get_next_line -I.
	./a.out ./test.cub
	rm a.out


clean:
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C $(MMS_DIR) clean
	$(MAKE) -C $(OPENGL_DIR) clean

re: fclean all


bonus: all
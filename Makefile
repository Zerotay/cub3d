NAME = cub3d

CC = gcc -Wall -Wextra -Werror
DY = libmlx.dylib
A = libmlx.a
# OBJS = $(SRCS:.c=.o)
SRCS = start.c

all: $(NAME)


$(NAME) :
	gcc ./*.c ./get_next_line/*.c -o $@ -Wall -Wextra -Werror \
	-L. -lft -I./libft -I./get_next_line -I. -lm \
	-L. -lmlx -framework Opengl -framework AppKit -lz -fsanitize=address
	./cub3d ./test.cub
	rm cub3d

clean:
	rm -rf $(NAME)

fclean: clean
	$(MAKE) -C $(MMS_DIR) clean
	$(MAKE) -C $(OPENGL_DIR) clean

re: fclean all


bonus: all

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

# define R 128
# define NO 64
# define SO 32
# define WE 16
# define EA 8
# define S 4
# define F 2
# define C 1
# define T_OK 255

# define CURR (char *)tmp->content
# define PREV (char *)tmp->prev->content
# define NEXT (char *)tmp->next->content

typedef struct  s_map
{
	unsigned char t_flag;

	int screen_x;
	int screen_y;
	char *i_no;
	char *i_so;
	char *i_ea;
	char *i_we;
	char *i_s;
	int c_floor;
	int c_ceiling;

	char m_flag;
	t_list	*map;
	int position_x;
	t_list	*position_y;

	char err;
}               t_map;

void	free_all(t_map map);
t_map	parse(char *gv, t_map map);

t_map	parse_type(t_map map, int fd);
t_map	fill_r(t_map map, char *line);
t_map	fill_no(t_map map, char *line);
t_map	fill_so(t_map map, char *line);
t_map	fill_we(t_map map, char *line);
t_map	fill_ea(t_map map, char *line);
t_map	fill_s(t_map map, char *line);
t_map	fill_f(t_map map, char *line);
t_map	fill_c(t_map map, char *line);

int		free_error(t_map map);
t_map	check_map_valid(t_map map, int i, t_list *tmp);
t_map	make_list(t_map map, int fd);
void	parse_map(t_map map);

#endif
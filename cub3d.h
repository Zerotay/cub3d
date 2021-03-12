#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

# define IS_R 128
# define IS_NO 64
# define IS_SO 32
# define IS_WE 16
# define IS_EA 8
# define IS_S 4
# define IS_F 2
# define IS_C 1
# define T_OK 255

# define W	1
# define A	2
# define S	4
# define D	8
# define R	16
# define L	32

# define MOVING_SPEED	0.05
# define MS				MOVING_SPEED
# define COLLISION_RANGE	0.4
# define CR				COLLISION_RANGE
# define TURN_RATE		0.05
# define TR				TURN_RATE

typedef struct s_map
{
	unsigned char	t_flag;
	int				sx;
	int				sy;
	char			*i_no;
	char			*i_so;
	char			*i_ea;
	char			*i_we;
	char			*i_s;
	int				c_floor;
	int				c_ceiling;
	char			m_flag;
	t_list			*map;
	int				px;
	t_list			*py;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		bpp;
	int		sl;
	int		en;
	char	*adr;
	int		height;
	int		width;
}				t_img;

typedef struct s_cub
{
	t_map	map;
	void	*mlx;
	void	*win;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
	t_img	img_s;
	t_img	scr;

	double	fovh;
	double	fovv;
	char	action;

	double	direction;
	double	deg;
	double	rx;
	double	ry;
	double	ft;
	double	gt;
	int		vx;
	int		vy;
	t_list	*curr;

	t_list	*spr;
	double	mid;
	double	edge;
	double	dist;

	char	*dst;
	char	*srcs;
	int		ax;
	int		ay;
	int		i;
}				t_cub;

/*
* sx,sy : screen. width and height of screen
* px,py : position. coorndinate of player in entire map
* rx,ry : real. exact location of player in 1*1 square
* vx,vy : vim! nexux between ony ray and integer of graph
* ax,ay : adress. adress of image
* ft,gt : function of ray, and the inverse's (fucntion, gunction)
*/

t_map	map_init(t_map map);
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

t_map	check_map_valid(t_map map, int i, t_list *tmp);
t_map	make_list(t_map map, int fd);
t_map	parse_map(t_map map);

void	display(t_map map);
int		gogo(t_cub *cub);
t_img	singlelight(t_cub cub, int ray);
t_cub	cub_setting(t_cub cub);
t_cub	cub_init(t_cub cub);

t_img	draw_spr(t_cub cub, int ray);
t_img	draw_ceiling(t_cub cub, int ray, int top);
t_img	draw_floor(t_cub cub, int ray, int i);
t_img	draw_no(t_cub cub, double x, double y, int ray);
t_img	draw_ea(t_cub cub, double x, double y, int ray);
t_img	draw_so(t_cub cub, double x, double y, int ray);
t_img	draw_we(t_cub cub, double x, double y, int ray);

void	link_spr(t_cub cub);
t_img	shoot_d(t_cub cub, int ray);
t_img	shoot_c(t_cub cub, int ray);
t_img	shoot_b(t_cub cub, int ray);
t_img	shoot_a(t_cub cub, int ray);
t_img	shoot_up(t_cub cub, int ray);
t_img	shoot_left(t_cub cub, int ray);
t_img	shoot_down(t_cub cub, int ray);
t_img	shoot_right(t_cub cub, int ray);

t_cub	move_forward(t_cub cub);
t_cub	move_backward(t_cub cub);
t_cub	move_left(t_cub cub);
t_cub	move_right(t_cub cub);
int		is_xcollission(t_cub cub, double x);
int		is_ycollission(t_cub cub, double y);

int		keyrelease(int keycode, t_cub *cub);
int		keypress(int keycode, t_cub *cub);
int		clientclick(t_cub *cub);

void	free_exit(t_cub cub);
void	free_mlx(t_cub cub);
void	free_map(t_map map);
int		free_error(t_map map);

int		make_bmp(char *gv);

#endif

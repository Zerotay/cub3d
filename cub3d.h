#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include "mlx.h"
#include <math.h>

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

#define KeyPress			2
#define KeyRelease			3
#define ButtonPress			4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify			7
#define LeaveNotify			8
#define FocusIn				9
#define FocusOut			10
#define KeymapNotify		11
#define Expose				12
#define GraphicsExpose		13
#define NoExpose			14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify			18
#define MapNotify			19
#define MapRequest			20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define GenericEvent		35
#define LASTEvent			36


#define POSITION			(char *)curr->content + cub.map.position_x

#define MOVING_SPEED	0.05
#define MS				MOVING_SPEED

#define COLLISION_RANGE	0.4
#define	CR				COLLISION_RANGE
#define	CURR_WALL		(char *)curr->content + cub.map.position_x
#define	NEXT_WALL		(char *)curr->next->content + cub.map.position_x
#define	PREV_WALL		(char *)curr->prev->content + cub.map.position_x

/*
   \ C | B /
    \  |  /
 D   \ | /   A
  -----------       X
 E   / | \   H
    /  |  \
   / F | G \

       |
   B   |   A
	   |
---------------    O
       |
   C   |   D
	   |
*/

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
}               t_map;

typedef struct s_img
{
	void	*img;
	int bpp;
    int sl;
    int en;
	char	*img_adrr;
	int	height;
	int	width;
}				t_img;

typedef struct	s_key
{
	int wmask;
	int	amask;
	int smask;
	int dmask;
	int leftmask;
	int rightmask;

}				t_key;

typedef struct	s_cub
{
	t_map	map;
	void	*mlx;
	void	*win;

	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
	t_img	img_s;
	t_img	screen;

	double	fovh;
	double	fovv;

	double	direction;
	double	deg;
	double	real_x;
	double	real_y;
	double	wall_x;
	double	wall_y;

	int		ray_x;
	int		ray_y;

	t_key	key;
	t_list	*spr;

	char	*dst;
	char	*srcs;
	int		adr_x;
	int		adr_y;
	int		i;
}				t_cub;

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
t_map	parse_map(t_map map);

void	display(t_map map);

#endif

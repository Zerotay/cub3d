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

#define NoEventMask					0L
#define KeyPressMask				(1L<<0)  
#define KeyReleaseMask				(1L<<1)  
#define ButtonPressMask				(1L<<2)  
#define ButtonReleaseMask			(1L<<3)  
#define EnterWindowMask				(1L<<4)  
#define LeaveWindowMask				(1L<<5)  
#define PointerMotionMask			(1L<<6)  
#define PointerMotionHintMask		(1L<<7)  
#define Button1MotionMask			(1L<<8)  
#define Button2MotionMask			(1L<<9)  
#define Button3MotionMask			(1L<<10) 
#define Button4MotionMask			(1L<<11) 
#define Button5MotionMask			(1L<<12) 
#define ButtonMotionMask			(1L<<13) 
#define KeymapStateMask				(1L<<14)
#define ExposureMask				(1L<<15) 
#define VisibilityChangeMask		(1L<<16) 
#define StructureNotifyMask			(1L<<17) 
#define ResizeRedirectMask			(1L<<18) 
#define SubstructureNotifyMask		(1L<<19) 
#define SubstructureRedirectMask	(1L<<20) 
#define FocusChangeMask				(1L<<21) 
#define PropertyChangeMask			(1L<<22) 
#define ColormapChangeMask			(1L<<23) 
#define OwnerGrabButtonMask			(1L<<24)

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

/*
   \ C | B / 
    \  |  /  
 D   \ | /   A
  -----------
 E   / | \   H
    /  |  \  
   / F | G \	
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
	double	real_x;
	double	real_y;
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
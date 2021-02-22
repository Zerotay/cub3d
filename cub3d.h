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

    char err;
}               t_map;


int parse(char *gv, t_map map);

#endif
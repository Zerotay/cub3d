#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
 
typedef struct s_val
{
    void *mlx;
    void *win;
    void *img1;
    void *img2;

    int bpp;
    int sl;
    int endian;
    char *imad;
    int x;
    int y;
    unsigned int color;

    char *dst;
    int i;
    int tcl;

    int i_width;
    int i_height;
}              t_val;

int main()
{
    t_val t;

    t.mlx = mlx_init();
    t.win = mlx_new_window(t.mlx, 720, 480, "아무 이미지");
    t.img1 = mlx_xpm_file_to_image(t.mlx, "./dngn_green_crystal_wall.xpm", &t.i_width, &t.i_height);
    printf("width is %d, height is %d\n", t.i_width, t.i_height);
    mlx_put_image_to_window(t.mlx, t.win, t.img1, 120, 60);
    mlx_loop(t.mlx);
}

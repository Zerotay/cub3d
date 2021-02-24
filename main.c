#include "cub3d.h"

void display(void)
{
	return ;
}

void	free_all(t_map map)
{
	if (map.i_so)
		free(map.i_so);
	if (map.i_no)
		free(map.i_no);
	if (map.i_we)
		free(map.i_we);
	if (map.i_ea)
		free(map.i_ea);
	if (map.i_s)
		free(map.i_s);
	if (map.map)
		ft_lstclear(&map.map, free);
	exit(0);
}

int main(int gc, char **gv)
{
	t_map map;

	if (gc == 3 && !ft_strncmp(gv[2], "--save", 6))
	{
		printf("wait for making\n");
		return (0);
	}
	else if (gc != 2 || ft_strncmp((gv[1] + ft_strlen(gv[1]) - 4), ".cub", 4))
	{
		printf("Error\n: not valid arguments\n");
		return (0);
	}
	else
	{
		map = parse(gv[1], map);
		display();
		free_all(map);
	}
	return (0);
}























// #include <stdio.h>
// #include <stdlib.h>
// #include "mlx.h"

// typedef struct s_val
// {
//     void *mlx;
//     void *win;
//     void *img1;
//     void *img2;

//     int bpp;
//     int sl;
//     int endian;
//     char *imad;
//     int x;
//     int y;
//     unsigned int color;

//     char *dst;
//     int i;
//     int tcl;

//     int i_width;
//     int i_height;
// }              t_val;

// int main()
// {
//     t_val t;

//     t.mlx = mlx_init();
//     t.win = mlx_new_window(t.mlx, 720, 480, "아무 이미지");
//     t.img1 = mlx_xpm_file_to_image(t.mlx, "./dngn_green_crystal_wall.xpm", &t.i_width, &t.i_height);
//     printf("width is %d, height is %d\n", t.i_width, t.i_height);
//     mlx_put_image_to_window(t.mlx, t.win, t.img1, 120, 60);
//     mlx_loop(t.mlx);
// }

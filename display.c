#include "cub3d.h"

t_cub	size_direction(t_cub cub)
{
	mlx_get_screen_size(cub.mlx, &cub.vx, &cub.vy);
	if (cub.vx < cub.map.sx)
		cub.map.sx = cub.vx;
	if (cub.vy < cub.map.sy)
		cub.map.sy = cub.vy;
	if (cub.map.m_flag == 'S')
		cub.direction = 3 * M_PI_2;
	else if (cub.map.m_flag == 'N')
		cub.direction = M_PI_2;
	else if (cub.map.m_flag == 'E')
		cub.direction = 0;
	else
		cub.direction = M_PI;
	return (cub);
}

t_cub	load_mlx_2(t_cub cub)
{
	cub.img_so.img = mlx_xpm_file_to_image(cub.mlx, \
				cub.map.i_so, &cub.img_so.width, &cub.img_so.height);
	if (!cub.img_so.img)
		free_exit(cub);
	cub.img_ea.img = mlx_xpm_file_to_image(cub.mlx, \
				cub.map.i_ea, &cub.img_ea.width, &cub.img_ea.height);
	if (!cub.img_ea.img)
		free_exit(cub);
	cub.img_we.img = mlx_xpm_file_to_image(cub.mlx, \
				cub.map.i_we, &cub.img_we.width, &cub.img_we.height);
	if (!cub.img_we.img)
		free_exit(cub);
	cub.img_s.img = mlx_xpm_file_to_image(cub.mlx, \
				cub.map.i_s, &cub.img_s.width, &cub.img_s.height);
	if (!cub.img_s.img)
		free_exit(cub);
	return (cub);
}

t_cub	load_mlx_1(t_cub cub)
{
	cub.mlx = mlx_init();
	if (!cub.mlx)
		free_exit(cub);
	cub.win = mlx_new_window(cub.mlx, cub.map.sx, cub.map.sy, "놈놈놈");
	if (!cub.win)
		free_exit(cub);
	cub.scr.img = mlx_new_image(cub.mlx, cub.map.sx, cub.map.sy);
	if (!cub.scr.img)
		free_exit(cub);
	cub.img_no.img = mlx_xpm_file_to_image(cub.mlx, \
				cub.map.i_no, &cub.img_no.width, &cub.img_no.height);
	if (!cub.img_no.img)
		free_exit(cub);
	return (cub);
}

t_cub	cub_setting(t_cub cub)
{
	cub = cub_init(cub);
	cub = load_mlx_1(cub);
	cub = load_mlx_2(cub);
	cub.scr.adr = mlx_get_data_addr(cub.scr.img, \
				&cub.scr.bpp, &cub.scr.sl, &cub.scr.en);
	cub.img_no.adr = mlx_get_data_addr(cub.img_no.img, \
				&cub.img_no.bpp, &cub.img_no.sl, &cub.img_no.en);
	cub.img_so.adr = mlx_get_data_addr(cub.img_so.img, \
				&cub.img_so.bpp, &cub.img_so.sl, &cub.img_so.en);
	cub.img_ea.adr = mlx_get_data_addr(cub.img_ea.img, \
				&cub.img_ea.bpp, &cub.img_ea.sl, &cub.img_ea.en);
	cub.img_we.adr = mlx_get_data_addr(cub.img_we.img, \
				&cub.img_we.bpp, &cub.img_we.sl, &cub.img_we.en);
	cub.img_s.adr = mlx_get_data_addr(cub.img_s.img, \
				&cub.img_s.bpp, &cub.img_s.sl, &cub.img_s.en);
	cub.fovh = M_PI / 3;
	cub.fovv = cub.fovh * cub.map.sy / cub.map.sx;
	cub = size_direction(cub);
	return (cub);
}

void	display(t_map map)
{
	t_cub	cub;

	cub.map = map;
	cub = cub_setting(cub);
	mlx_hook(cub.win, 3, 0, keyrelease, &cub);
	mlx_hook(cub.win, 2, 0, keypress, &cub);
	mlx_hook(cub.win, 17, 0, clientclick, &cub);
	mlx_loop_hook(cub.mlx, gogo, &cub);
	mlx_loop(cub.mlx);
}

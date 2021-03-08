#include "cub3d.h"

t_cub   cub_init(t_cub cub)
{
	cub.mlx = 0;
	cub.win = 0;
	cub.img_we.img = 0;
	cub.img_ea.img = 0;
	cub.img_s.img = 0;
	cub.img_no.img = 0;
	cub.img_so.img = 0;
	cub.rx = 0.5;
	cub.ry = 0.5;
	cub.action = 0;
	return (cub);
}

void    free_mlx(t_cub cub)
{
	if (cub.img_ea.img)
		mlx_destroy_image(cub.mlx, cub.img_ea.img);
	if (cub.img_no.img)
		mlx_destroy_image(cub.mlx, cub.img_no.img);
	if (cub.img_s.img)
		mlx_destroy_image(cub.mlx, cub.img_s.img);
	if (cub.img_so.img)
		mlx_destroy_image(cub.mlx, cub.img_so.img);
	if (cub.img_we.img)
		mlx_destroy_image(cub.mlx, cub.img_we.img);
	if (cub.scr.img)
		mlx_destroy_image(cub.mlx, cub.scr.img);
	if (cub.win)
		mlx_destroy_window(cub.mlx, cub.win);
}

void	free_exit(t_cub cub)
{
	free_mlx(cub);
	ft_lstclear(&cub.spr, free);
	free_error(cub.map);
}


t_img shoot_up(t_cub cub, int ray)
{
	double  light_y;
	t_list  *curr;

	light_y = 1;
	curr = cub.map.py;
	while (1)
	{
		curr = curr->prev;
		if (*((char *)curr->content + cub.map.px) == '1')
            return (draw_so(cub, cub.rx, light_y, ray));
		else
			light_y++;
	}
	return (cub.scr);
}

t_img shoot_left(t_cub cub, int ray)
{
	double  light_x;
	t_list  *curr;

	light_x = 0;
	curr = cub.map.py;
	while (1)
	{
		if (*((char *)curr->content + cub.map.px + (int)light_x) == '1')
            return (draw_ea(cub, light_x, cub.ry, ray));
		else
			light_x--;
	}
	return (cub.scr);
}

t_img shoot_down(t_cub cub, int ray)
{
	double  light_y;
	t_list  *curr;

	light_y = 0;
	curr = cub.map.py;
	while (1)
	{
		curr = curr->next;
		if (*((char *)curr->content + cub.map.px) == '1')
            return (draw_no(cub, cub.rx, light_y, ray));
		else
			light_y--;
	}
	return (cub.scr);
}

t_img shoot_right(t_cub cub, int ray)
{
	double  light_x;
	t_list  *curr;

	light_x = 1;
	curr = cub.map.py;
	while (1)
	{
		if (*((char *)curr->content + cub.map.px) == '1')
            return (draw_we(cub, light_x, cub.ry, ray));
		else
			light_x++;
	}
	return (cub.scr);
}


int is_xcollission(t_cub cub, double x)
{
	t_list	*curr;

	curr = cub.map.py;
	if (x < CR && *((char *)curr->content + cub.map.px - 1) == '1')
		return (1);
	if (x > 1 - CR && *((char *)curr->content + cub.map.px + 1) == '1')
		return (1);
	if (x < CR && cub.ry < CR && *((char *)curr->next->content + cub.map.px - 1) == '1')
		return (1);
	if (x < CR && cub.ry > 1 - CR && *((char *)curr->prev->content + cub.map.px - 1) == '1')
		return (1);
	if (x > 1 - CR && cub.ry < CR && *((char *)curr->next->content + cub.map.px + 1) == '1')
		return (1);
	if (x > 1 - CR && cub.ry > 1 - CR && *((char *)curr->prev->content + cub.map.px + 1) == '1')
		return (1);
	return (0);
}

int is_ycollission(t_cub cub, double y)
{
	t_list	*curr;

	curr = cub.map.py;
	if (y < CR && *((char *)curr->next->content + cub.map.px) == '1')
		return (1);
	if (y > 1 - CR && *((char *)curr->prev->content + cub.map.px) == '1')
		return (1);
	if (cub.rx < CR && y < CR && *((char *)curr->next->content + cub.map.px - 1) == '1')
		return (1);
	if (cub.rx < CR && y > 1 - CR && *((char *)curr->prev->content + cub.map.px - 1) == '1')
		return (1);
	if (cub.rx > 1 - CR && y < CR && *((char *)curr->next->content + cub.map.px + 1) == '1')
		return (1);
	if (cub.rx > 1 - CR && y > 1 - CR && *((char *)curr->prev->content + cub.map.px + 1) == '1')
		return (1);
	return (0);
}



int     key(int keycode, t_cub *cub)
{
	if (keycode == 53)
	{
		free_all(cub->map);
		free_mlx(*cub);
		printf("bye~~\n");
		exit(0);
	}
	if (keycode == 123)
		cub->action |= L;
	if (keycode == 124)
		cub->action |= R;
	if (keycode == 13)
		cub->action |= W;
	if (keycode == 1)
		cub->action |= S;
	if (keycode == 0)
		cub->action |= A;
	if (keycode == 2)
		cub->action |= D;
	return (0);
}

int keyend(int keycode, t_cub *cub)
{
	if (keycode == 123)
		cub->action ^= L;
	if (keycode == 124)
		cub->action ^= R;
	if (keycode == 13)
		cub->action ^= W;
	if (keycode == 1)
		cub->action ^= S;
	if (keycode == 0)
		cub->action ^= A;
	if (keycode == 2)
		cub->action ^= D;
	return (0);
}

t_img singlelight(t_cub cub, int ray)
{
	double deg;
	char news;
	double dist;
	double	len;


	cub.deg = (cub.direction + cub.fovh / 2) - cub.fovh / (cub.map.screen_x - 1) * ray;
	while (cub.deg >= 2 * M_PI)
		cub.deg -= 2 * M_PI;
	while (cub.deg < 0)
		cub.deg += 2 * M_PI;


	cub.spr = (t_list*)malloc(sizeof(t_list));
	if (!cub.spr)
		free_error(cub.map);
	cub.spr->content = 0;
	cub.spr->next = 0;
	cub.spr->prev = 0;

	deg = cub.deg;
	if (cub.deg > 0 && cub.deg < M_PI_2)
		return (shoot_a(cub, cub.deg, ray));
	if (cub.deg > M_PI_2 && cub.deg < M_PI)
		return (shoot_b(cub, cub.deg, ray));
	if (cub.deg > M_PI && cub.deg < 3 * M_PI_2)
		return (shoot_c(cub, cub.deg, ray));
	if (cub.deg > 3 * M_PI_2 && cub.deg < 2 * M_PI)
		return (shoot_d(cub, cub.deg, ray));
	if (cub.deg == M_PI_2)
		return (shoot_up(cub, ray));
	if (cub.deg == M_PI)
		return (shoot_left(cub, ray));
	if (cub.deg == 3 * M_PI_2)
		return (shoot_down(cub, ray));
	if (cub.deg == 0)
		return (shoot_right(cub, ray));
	return (cub.scr);
}

int gogo(t_cub *cub)
{
	int	ray;

	if (cub->action & W)
		*cub = move_forward(*cub);
	if (cub->action & S)
		*cub = move_backward(*cub);
	if (cub->action & A)
		*cub = move_left(*cub);
	if (cub->action & D)
		*cub = move_right(*cub);
	if (cub->action & R)
		cub->direction -= 0.05;
	if (cub->action & L)
		cub->direction += 0.05;
	ray = -1;
	while (++ray < cub->map.screen_x)
		cub->scr = singlelight(*cub, ray);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->scr.img, 0, 0);
	return (0);
}


void    display(t_map map)
{
	t_cub cub;

	cub.map = map;
	cub = cub_init(cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, map.screen_x, map.screen_y, "놈놈놈");

	cub.scr.img = mlx_new_image(cub.mlx, map.screen_x, map.screen_y);
	cub.img_no.img = mlx_xpm_file_to_image(cub.mlx, map.i_no, &cub.img_no.width, &cub.img_no.height);
	cub.img_so.img = mlx_xpm_file_to_image(cub.mlx, map.i_so, &cub.img_so.width, &cub.img_so.height);
	cub.img_ea.img = mlx_xpm_file_to_image(cub.mlx, map.i_ea, &cub.img_ea.width, &cub.img_ea.height);
	cub.img_we.img = mlx_xpm_file_to_image(cub.mlx, map.i_we, &cub.img_we.width, &cub.img_we.height);
	cub.img_s.img = mlx_xpm_file_to_image(cub.mlx, map.i_s, &cub.img_s.width, &cub.img_s.height);

    cub.scr.i_adr = mlx_get_data_addr(cub.scr.img, &cub.scr.bpp, &cub.scr.sl, &cub.scr.en);
	cub.img_no.i_adr = mlx_get_data_addr(cub.img_no.img, &cub.img_no.bpp, &cub.img_no.sl, &cub.img_no.en);
	cub.img_so.i_adr = mlx_get_data_addr(cub.img_so.img, &cub.img_so.bpp, &cub.img_so.sl, &cub.img_so.en);
	cub.img_ea.i_adr = mlx_get_data_addr(cub.img_ea.img, &cub.img_ea.bpp, &cub.img_ea.sl, &cub.img_ea.en);
	cub.img_we.i_adr = mlx_get_data_addr(cub.img_we.img, &cub.img_we.bpp, &cub.img_we.sl, &cub.img_we.en);
	cub.img_s.i_adr = mlx_get_data_addr(cub.img_s.img, &cub.img_s.bpp, &cub.img_s.sl, &cub.img_s.en);

	cub.fovh = M_PI / 3;
	cub.fovv = cub.fovh * cub.map.screen_y / cub.map.screen_x;

	if (cub.map.m_flag == 'S')
		cub.direction = 3 * M_PI_2;
	else if (cub.map.m_flag == 'N')
		cub.direction = M_PI_2;
	else if (cub.map.m_flag == 'E')
		cub.direction = 0;
	else
		cub.direction = M_PI;

	mlx_hook(cub.win, 3, 0, keyend, &cub);
	mlx_hook(cub.win, 2, 0, key, &cub);

	mlx_loop_hook(cub.mlx, gogo, &cub);

	mlx_loop(cub.mlx);
}

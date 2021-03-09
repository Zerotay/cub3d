#include "cub3d.h"

double  make_deg(t_cub cub, int ray)
{
	cub.deg = (cub.direction + cub.fovh / 2) - cub.fovh / (cub.map.screen_x - 1) * ray;
	while (cub.deg >= 2 * M_PI)
		cub.deg -= 2 * M_PI;
	while (cub.deg < 0)
		cub.deg += 2 * M_PI;
    return (cub.deg);
}

t_img singlelight(t_cub cub, int ray)
{
    cub.deg = make_deg(cub, ray);
    cub.spr = ft_lstnew(0);
    if (!cub.spr)
        free_exit(cub);
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
		cub->direction -= TR;
	if (cub->action & L)
		cub->direction += TR;
	ray = -1;
	while (++ray < cub->map.screen_x)
		cub->scr = singlelight(*cub, ray);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->scr.img, 0, 0);
	return (0);
}
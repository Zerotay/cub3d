#include "cub3d.h"

t_img	draw_ea_wall(t_cub cub, int *i, int height, int ray)
{
	int		top;
	int		tmp;

    top = (cub.map.screen_y / 2) - (height / 2);
	tmp = top;
	while ((*i)++ < height + tmp)
    {
        cub.adr_y = (top - tmp) * cub.img_ea.height / height;
        cub.dst = cub.scr.i_adr + (top * cub.scr.sl + ray * (cub.scr.bpp / 8));
        cub.srcs = cub.img_ea.i_adr + (cub.adr_y * cub.img_ea.sl + cub.adr_x * (cub.img_ea.bpp / 8));
        top++;
		if (top <= 0)
        {
            top += (height - cub.map.screen_y) / 2;
            *i += (height - cub.map.screen_y) / 2;
            continue;
        }
        if (top >= cub.map.screen_y)
            break;
        *(unsigned int *)cub.dst = *(unsigned int *)cub.srcs;
    }
	return (cub.scr);
}

t_cub   draw_ea(t_cub cub, double x, double y, int ray)
{
    double dist;
    int wall_height;
    int top;
    int i;

    dist = hypot(x - cub.real_x, y - cub.real_y);
	dist *= cos(cub.direction - cub.deg);
    if (y < 0)
    	cub.adr_x = cub.img_ea.width + trunc((y - trunc(y)) * cub.img_ea.width) - 1;
	else
    	cub.adr_x = trunc((y - trunc(y)) * cub.img_ea.width);
    wall_height = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
    top = (cub.map.screen_y / 2) - (wall_height / 2);
    i = top;
	cub.scr = draw_ceiling(cub, ray, top);
	cub.scr = draw_ea_wall(cub, &i, wall_height, ray);
	cub.scr = draw_floor(cub, ray, i);
	cub.scr = draw_spr(cub, ray);
    return (cub);
}

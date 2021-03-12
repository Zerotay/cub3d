#include "cub3d.h" 

t_img	draw_ceiling(t_cub cub, int ray, int top)
{
	int	i;

	i = -1;
	while (++i < top)
	{
		cub.dst = cub.scr.adr + (i * cub.scr.sl + ray * (cub.scr.bpp / 8));
		*(unsigned int *)cub.dst = cub.map.c_ceiling;
	}
	return (cub.scr);
}

t_img	draw_floor(t_cub cub, int ray, int i)
{
	while (i < cub.map.sy)
	{
		cub.dst = cub.scr.adr + ((i++) * \
				cub.scr.sl + ray * (cub.scr.bpp / 8));
		*(unsigned int *)cub.dst = cub.map.c_floor;
	}
	return (cub.scr);
}

// #include "cub3d.h"

// t_img	draw_ceiling(t_cub cub, int ray, int top)
// {
// 	int	i;

// 	i = -1;

// 	while (++i < top)
// 	{
//         cub.dst = cub.scr.i_adr + (i * cub.scr.sl + ray * (cub.scr.bpp / 8));
//         *(unsigned int *)cub.dst = cub.map.c_ceiling;
// 	}
// 	// cub.dst = cub.scr.i_adr + (i * cub.scr.sl + ray * (cub.scr.bpp / 8));
// 	// *(unsigned int *)cub.dst = color;
// 	return(cub.scr);
// }

// t_img	draw_floor(t_cub cub, int ray, int i)
// {

// 	while (++i < cub.map.screen_y)
// 	{
//         cub.dst = cub.scr.i_adr + (i * cub.scr.sl + ray * (cub.scr.bpp / 8));
//         *(unsigned int *)cub.dst = cub.map.c_floor;
// 	}
// 	return (cub.scr);
// }

// t_cub	draw_no_wall(t_cub cub, int *i, int height, int ray)
// {
// 	int		top;
// 	int		tmp;

//     top = (cub.map.screen_y / 2) - (height / 2);
// 	tmp = top;
// 	while ((*i)++ < height + tmp)
//     {
//         cub.adr_y = (top - tmp) * cub.img_no.height / height;
//         cub.dst = cub.scr.i_adr + (top * cub.scr.sl + ray * (cub.scr.bpp / 8));
//         cub.srcs = cub.img_no.i_adr + (cub.adr_y * cub.img_no.sl + cub.adr_x * (cub.img_no.bpp / 8));
//         top++;
// 		if (top <= 0 || top >= cub.map.screen_y)
// 			continue;
//         *(unsigned int *)cub.dst = *(unsigned char *)cub.srcs;
//     }
// 	return (cub);
// }

// t_cub   draw_no(t_cub cub, double x, double y, int ray)
// {
//     double dist;
//     int wall_height;
//     int top;

//     dist = hypot(x - cub.real_x, y - cub.real_y);
// 	dist *= cos(cub.direction - cub.deg);
// 	if (x < 0)
// 		cub.adr_x = trunc((x - trunc(x)) * -1 * cub.img_no.width) + 1;
// 	else
// 		cub.adr_x = cub.img_no.width - trunc((x - trunc(x))* cub.img_no.width);
//     wall_height = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
//     top = (cub.map.screen_y / 2) - (wall_height / 2);
//     int i = top;
// 	cub.scr = draw_ceiling(cub, ray, top);
// 	cub = draw_no_wall(cub, &i, wall_height, ray);
// 	cub.scr = draw_floor(cub, ray, i);
// 	cub.scr = draw_spr(cub, ray);
//     return (cub);
// }

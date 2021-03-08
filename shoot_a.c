#include "cub3d.h"

void	a_we_spr(t_cub cub)
{
	cub.mid = atan2((trunc(cub.ft) + 0.5 - cub.ry), (cub.vx + 0.5 - cub.rx));
	cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.ry, cub.vx + 0.5 - cub.rx);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

void	a_so_spr(t_cub cub)
{
	cub.mid = atan2((cub.vy + 0.5 - cub.ry), (trunc(cub.gt) + 0.5 - cub.rx));
	cub.dist = hypot(cub.vy + 0.5 - cub.ry, trunc(cub.gt) + 0.5 - cub.rx);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

t_cub	a_init(t_cub cub)
{
	cub.vx = 1;
	cub.vy = 1;
	cub.curr = cub.map.py;
	return (cub);
}

t_img shoot_a(t_cub cub, double deg, int ray)
{
	cub = a_init(cub);
	while (1)
	{
		cub.ft = tan(cub.deg) * (cub.vx - cub.rx) + cub.ry;
		cub.gt = (1 / tan(cub.deg)) * (cub.vy - cub.ry) + cub.rx;

		if (hypot(cub.vx, cub.ft) < hypot(cub.vy, cub.gt))
		{
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '1')
				return (draw_we(cub, cub.vx, cub.ft, ray));
			else if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '2')
				a_we_spr(cub);
			cub.vx++;
		}
		else
		{
			cub.curr = cub.curr->prev;
			if (*((char *)cub.curr->content + cub.map.px + cub.vx - 1) == '1')
				return (draw_so(cub, cub.gt, cub.vy, ray));
			else if (*((char *)cub.curr->content + cub.map.px + cub.vx - 1) == '2')
				a_so_spr(cub);
			cub.vy++;
		}
	}
}
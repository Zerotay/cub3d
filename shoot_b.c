#include "cub3d.h"

void	b_ea_spr(t_cub cub)
{
	cub.mid = atan2((trunc(cub.ft) + 0.5 - cub.ry), (cub.vx - 0.5 - cub.rx));
	cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.ry, cub.vx - 0.5 - cub.rx);
	if (cub.vy == 1 && cub.ry > 0.5 && cub.ry < 1)
	{
		cub.mid = atan2((trunc(cub.ft) + 0.5 - cub.ry), \
						(cub.vx - 0.5 - cub.rx)) + 2 * M_PI;
		cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.ry, cub.vx - 0.5 - cub.rx);
	}
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

void	b_so_spr(t_cub cub)
{
	cub.mid = atan2((cub.vy + 0.5 - cub.ry), (trunc(cub.gt) - 0.5 - cub.rx));
	cub.dist = hypot(cub.vy + 0.5 - cub.ry, trunc(cub.gt) - 0.5 - cub.rx);
	if (!cub.vx)
	{
		cub.mid = atan2((cub.vy + 0.5 - cub.ry), \
						(trunc(cub.gt) + 0.5 - cub.rx));
		cub.dist = hypot(cub.vy + 0.5 - cub.ry, trunc(cub.gt) + 0.5 - cub.rx);
	}
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

t_cub	b_init(t_cub cub)
{
	cub.vx = 0;
	cub.vy = 1;
	cub.curr = cub.map.py;
	return (cub);
}

t_img	shoot_b(t_cub cub, int ray)
{
	cub = b_init(cub);
	while (1)
	{
		cub.ft = tan(cub.deg) * (cub.vx - cub.rx) + cub.ry;
		cub.gt = (1 / tan(cub.deg)) * (cub.vy - cub.ry) + cub.rx;
		if (hypot(cub.vx - cub.rx, cub.ft - cub.ry) < \
			hypot(cub.vy - cub.ry, cub.gt - cub.rx))
		{
			if (*((char *)cub.curr->content + cub.map.px + cub.vx - 1) == '1')
				return (draw_ea(cub, cub.vx, cub.ft, ray));
			if (*((char *)cub.curr->content + cub.map.px + cub.vx - 1) == '2')
				b_ea_spr(cub);
			cub.vx--;
		}
		else
		{
			cub.curr = cub.curr->prev;
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '1')
				return (draw_so(cub, cub.gt, cub.vy, ray));
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '2')
				b_so_spr(cub);
			cub.vy++;
		}
	}
}

#include "cub3d.h"

void	link_spr(t_cub cub)
{
	t_list	*scurr;
	int		*arr;

	arr = (int *)malloc(sizeof(int) * 2);
	if (!arr)
		free_exit(cub);
	scurr = ft_lstnew(arr);
	if (!scurr)
	{
		free(arr);
		ft_lstclear(&cub.spr, free);
		free_exit(cub);
	}
	ft_lstadd_back(&cub.spr, scurr);
	*((int *)scurr->content) = (int)trunc((cub.mid + \
			cub.edge - cub.deg) * cub.img_s.width / (2 * cub.edge));
	*((int *)scurr->content + 1) = (int)(cub.map.sy / \
			(2 * cub.dist * tan(cub.fovv / 2)));
}

void	d_we_spr(t_cub cub)
{
	cub.mid = atan2((trunc(cub.ft) - 0.5 - cub.ry), \
					(cub.vx + 0.5 - cub.rx)) + 2 * M_PI;
	cub.dist = hypot(trunc(cub.ft) - 0.5 - cub.ry, cub.vx + 0.5 - cub.rx);
	if (!cub.vy)
		cub.mid = atan2((trunc(cub.ft) + 0.5 - cub.ry), \
					(cub.vx + 0.5 - cub.rx)) + 2 * M_PI;
	if (!cub.vy)
		cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.ry, cub.vx + 0.5 - cub.rx);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

void	d_no_spr(t_cub cub)
{
	cub.mid = atan2((cub.vy - 0.5 - cub.ry), \
					(trunc(cub.gt) + 0.5 - cub.rx)) + 2 * M_PI;
	cub.dist = hypot(cub.vy - 0.5 - cub.ry, trunc(cub.gt) + 0.5 - cub.rx);
	if (cub.rx > 0.5 && cub.rx < 1 && cub.vx == 1 && cub.vy == 0)
		cub.mid = atan2((cub.vy - 0.5 - cub.ry), \
					(trunc(cub.gt) + 0.5 - cub.rx)) + 2 * M_PI;
	if (cub.rx > 0.5 && cub.rx < 1 && cub.vx == 1 && cub.vy == 0)
		cub.dist = hypot(cub.vy - 0.5 - cub.ry, trunc(cub.gt) + 0.5 - cub.rx);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

t_cub	d_init(t_cub cub)
{
	cub.vx = 1;
	cub.vy = 0;
	cub.curr = cub.map.py;
	return (cub);
}

t_img	shoot_d(t_cub cub, int ray)
{
	cub = d_init(cub);
	while (1)
	{
		cub.ft = tan(cub.deg) * (cub.vx - cub.rx) + cub.ry;
		cub.gt = (1 / tan(cub.deg)) * (cub.vy - cub.ry) + cub.rx;
		if (hypot(cub.vx - cub.rx, cub.ft - cub.ry) < \
			hypot(cub.vy - cub.ry, cub.gt - cub.rx))
		{
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '1')
				return (draw_we(cub, cub.vx, cub.ft, ray));
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '2')
				d_we_spr(cub);
			cub.vx++;
		}
		else
		{
			cub.curr = cub.curr->next;
			if (*((char *)cub.curr->content + cub.map.px + cub.vx - 1) == '1')
				return (draw_no(cub, cub.gt, cub.vy, ray));
			if (*((char *)cub.curr->content + cub.map.px + cub.vx - 1) == '2')
				d_no_spr(cub);
			cub.vy--;
		}
	}
}

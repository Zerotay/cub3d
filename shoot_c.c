/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:45 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:46 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c_ea_spr(t_cub cub)
{
	cub.mid = atan2((trunc(cub.ft) - 0.5 - cub.ry), \
					(cub.vx - 0.5 - cub.rx)) + 2 * M_PI;
	cub.dist = hypot(trunc(cub.ft) - 0.5 - cub.ry, cub.vx - 0.5 - cub.rx);
	if (cub.ry - cub.vy <= 0.5 && cub.ry - cub.vy > 0)
		cub.mid = atan2(trunc(cub.ft) + 0.5 - cub.ry, (cub.vx - 0.5 - cub.rx));
	if (cub.ry - cub.vy <= 0.5 && cub.ry - cub.vy > 0)
		cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.ry, \
						(cub.vx - 0.5 - cub.rx));
	if (cub.ry - cub.vy < 1 && cub.ry - cub.vy > 0.5)
		cub.mid = atan2(trunc(cub.ft) + 0.5 - cub.ry, \
						(cub.vx - 0.5 - cub.rx)) + 2 * M_PI;
	if (cub.ry - cub.vy < 1 && cub.ry - cub.vy > 0.5)
		cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.ry, \
						(cub.vx - 0.5 - cub.rx));
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

void	c_no_spr(t_cub cub)
{
	cub.mid = atan2((cub.vy - 0.5 - cub.ry), \
					(trunc(cub.gt) - 0.5 - cub.rx)) + 2 * M_PI;
	cub.dist = hypot(cub.vy - 0.5 - cub.ry, trunc(cub.gt) - 0.5 - cub.rx);
	if (!cub.vx)
		cub.mid = atan2((cub.vy - 0.5 - cub.ry), \
					(trunc(cub.gt) + 0.5 - cub.rx)) + 2 * M_PI;
	if (!cub.vx)
		cub.dist = hypot(cub.vy - 0.5 - cub.ry, trunc(cub.gt) + 0.5 - cub.rx);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

t_cub	c_init(t_cub cub)
{
	cub.vx = 0;
	cub.vy = 0;
	cub.curr = cub.map.py;
	return (cub);
}

t_img	shoot_c(t_cub cub, int ray)
{
	cub = c_init(cub);
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
				c_ea_spr(cub);
			cub.vx--;
		}
		else
		{
			cub.curr = cub.curr->next;
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '1')
				return (draw_no(cub, cub.gt, cub.vy, ray));
			if (*((char *)cub.curr->content + cub.map.px + cub.vx) == '2')
				c_no_spr(cub);
			cub.vy--;
		}
	}
}

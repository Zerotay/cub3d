#include "cub3d.h"

t_cub	stabilize_position(t_cub cub)
{
	if (cub.rx >= 1)
	{
		cub.rx -= 1;
		cub.map.px++;
	}
	else if (cub.rx < 0)
	{
		cub.rx += 1;
		cub.map.px--;
	}
	if (cub.ry >= 1)
	{
		cub.ry -= 1;
		cub.map.py = cub.map.py->prev;
	}
	if (cub.ry < 0)
	{
		cub.ry += 1;
		cub.map.py = cub.map.py->next;
	}
	return (cub);
}

t_cub	move_forward(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx + MS * cos(cub.direction)))
		cub.rx += MS * cos(cub.direction);
	if (!is_ycollission(cub, cub.ry + MS * sin(cub.direction)))
		cub.ry += MS * sin(cub.direction);
	cub = stabilize_position(cub);
	return (cub);
}

t_cub	move_backward(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx - MS * cos(cub.direction)))
		cub.rx -= MS * cos(cub.direction);
	if (!is_ycollission(cub, cub.ry - MS * sin(cub.direction)))
		cub.ry -= MS * sin(cub.direction);
	cub = stabilize_position(cub);
	return (cub);
}

t_cub	move_left(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx - MS * cos(cub.direction - M_PI_2)))
		cub.rx -= MS * cos(cub.direction - M_PI_2);
	if (!is_ycollission(cub, cub.ry - MS * sin(cub.direction - M_PI_2)))
		cub.ry -= MS * sin(cub.direction - M_PI_2);
	cub = stabilize_position(cub);
	return (cub);
}

t_cub	move_right(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx - MS * cos(cub.direction + M_PI_2)))
		cub.rx -= MS * cos(cub.direction + M_PI_2);
	if (!is_ycollission(cub, cub.ry - MS * sin(cub.direction + M_PI_2)))
		cub.ry -= MS * sin(cub.direction + M_PI_2);
	cub = stabilize_position(cub);
	return (cub);
}

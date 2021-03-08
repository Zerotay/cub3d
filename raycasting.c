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

t_cub move_forward(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx + MS * cos(cub.direction)))
		cub.rx += MS * cos(cub.direction);
	if (!is_ycollission(cub, cub.ry + MS * sin(cub.direction)))
		cub.ry += MS * sin(cub.direction);
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

t_cub move_backward(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx - MS * cos(cub.direction)))
		cub.rx -= MS * cos(cub.direction);
	if (!is_ycollission(cub, cub.ry - MS * sin(cub.direction)))
		cub.ry -= MS * sin(cub.direction);
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

t_cub move_left(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx - MS * cos(cub.direction - M_PI_2)))
		cub.rx -= MS * cos(cub.direction - M_PI_2);
	if (!is_ycollission(cub, cub.ry - MS * sin(cub.direction - M_PI_2)))
		cub.ry -= MS * sin(cub.direction - M_PI_2);
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

t_cub move_right(t_cub cub)
{
	if (!is_xcollission(cub, cub.rx - MS * cos(cub.direction + M_PI_2)))
		cub.rx -= MS * cos(cub.direction + M_PI_2);
	if (!is_ycollission(cub, cub.ry - MS * sin(cub.direction + M_PI_2)))
		cub.ry -= MS * sin(cub.direction + M_PI_2);
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
		cub->key.leftmask = 1;
	if (keycode == 124)
		cub->key.rightmask = 1;
	if (keycode == 13)
		cub->key.wmask = 1;
	if (keycode == 1)
		cub->key.amask = 1;
	if (keycode == 0)
		cub->key.smask = 1;
	if (keycode == 2)
		cub->key.dmask = 1;
	return (0);
}

int keyend(int keycode, t_cub *cub)
{
	if (keycode == 123)
		cub->key.leftmask = 0;
	if (keycode == 124)
		cub->key.rightmask = 0;
	if (keycode == 13)
		cub->key.wmask = 0;
	if (keycode == 1)
		cub->key.amask = 0;
	if (keycode == 0)
		cub->key.smask = 0;
	if (keycode == 2)
		cub->key.dmask = 0;
	return (0);
}





t_img shoot_c(t_cub cub, double deg, int ray)
{
	double  light_x;
	double  light_y;
	double  func;
	double  gunc;
	t_list  *curr;

	double	mid;
	double	edge;
	t_list	*scurr;
	double	dist;
	int	*arr;

	light_x = 0;
	light_y = 0;
	curr = cub.map.py;
	while (1)
	{
		func = tan(deg) * (light_x - cub.rx) + cub.ry;
		gunc = (1 / tan(deg)) * (light_y - cub.ry) + cub.rx;

		if (hypot(light_x - cub.rx, func - cub.ry) < hypot(light_y - cub.ry, gunc - cub.rx))
		{
			if (*((char *)curr->content + cub.map.px + (int)light_x - 1) == '1')
                return (draw_ea(cub, light_x, func, ray));
			else if (*((char *)curr->content + cub.map.px + (int)light_x - 1) == '2')
			{
				mid = atan2((trunc(func) - 0.5 - cub.ry), (light_x - 0.5 - cub.rx)) + 2 * M_PI;
				dist = hypot(trunc(func) - 0.5 - cub.ry, light_x - 0.5 - cub.rx);
				if (cub.ry - light_y <= 0.5 && cub.ry - light_y > 0)
				{
					mid = atan2(trunc(func) + 0.5 - cub.ry, (light_x - 0.5 - cub.rx));
					// printf("lightxy : %d %d\n", (int)light_x, (int)light_y);
					dist = hypot(trunc(func) + 0.5 - cub.ry, (light_x - 0.5 - cub.rx));
				}
				if (cub.ry - light_y < 1 && cub.ry - light_y > 0.5)
				{
					mid = atan2(trunc(func) + 0.5 - cub.ry, (light_x - 0.5 - cub.rx)) + 2 * M_PI;
					// printf("lightxy : %d %d\n", (int)light_x, (int)light_y);
					dist = hypot(trunc(func) + 0.5 - cub.ry, (light_x - 0.5 - cub.rx));
				}
				edge = atan(0.5 / dist);
				// printf("mid, edge, deg : %f, %f, %f\n", mid, edge, deg);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (int *)malloc(sizeof(int) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((int *)scurr->content) = (int)trunc((mid + edge - deg) * cub.img_s.width / (2 * edge));
					// printf("error1\n");
					*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_x--;
			}
			else
				light_x--;
		}
		else
		{
			curr = curr->next;
			if (*((char *)curr->content + cub.map.px + (int)light_x) == '1')
                return (draw_no(cub, gunc, light_y, ray));
			else if (*((char *)curr->content + cub.map.px + (int)light_x) == '2')
			{
				mid = atan2((light_y - 0.5 - cub.ry), (trunc(gunc) - 0.5 - cub.rx)) + 2 * M_PI;
				dist = hypot(light_y - 0.5 - cub.ry, trunc(gunc) - 0.5 - cub.rx);
				if (!light_x)
				{
					mid = atan2((light_y - 0.5 - cub.ry), (trunc(gunc) + 0.5 - cub.rx)) + 2 * M_PI;
					dist = hypot(light_y - 0.5 - cub.ry, trunc(gunc) + 0.5 - cub.rx);
					// printf("error1\n");
				}
				edge = atan(0.5 / dist);
				// printf("mid, edge, deg : %f, %f, %f\n", mid, edge, deg);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (int *)malloc(sizeof(int) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((int *)scurr->content) = (int)trunc((mid + edge - deg) * cub.img_s.width / (2 * edge));
					// printf("error1\n");
					*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_y--;
			}
			else
				light_y--;
		}
	}
}

t_img shoot_b(t_cub cub, double deg, int ray)
{
	double  light_x;
	double  light_y;
	double  func;
	double  gunc;
	t_list  *curr;

	double	mid;
	double	edge;
	t_list	*scurr;
	double	dist;
	int	*arr;

	light_x = 0;
	light_y = 1;
	curr = cub.map.py;
	while (1)
	{
		func = tan(deg) * (light_x - cub.rx) + cub.ry;
		gunc = (1 / tan(deg)) * (light_y - cub.ry) + cub.rx;

		if (hypot(light_x - cub.rx, func - cub.ry) < hypot(light_y - cub.ry, gunc - cub.rx))
		{
			if (*((char *)curr->content + cub.map.px + (int)light_x - 1) == '1')
                return (draw_ea(cub, light_x, func, ray));
			else if (*((char *)curr->content + cub.map.px + (int)light_x - 1) == '2')
			{
				mid = atan2((trunc(func) + 0.5 - cub.ry), (light_x - 0.5 - cub.rx));
				dist = hypot(trunc(func) + 0.5 - cub.ry, light_x - 0.5 - cub.rx);
					// printf("lightxy : %d %d\n", (int)light_x, (int)light_y);
				if (light_y == 1 && cub.ry > 0.5 && cub.ry < 1)
				{
					mid = atan2((trunc(func) + 0.5 - cub.ry), (light_x - 0.5 - cub.rx))+ 2 * M_PI;
					dist = hypot(trunc(func) + 0.5 - cub.ry, light_x - 0.5 - cub.rx);
					// printf("error1\n");
				}
				edge = atan(0.5 / dist);
				// printf("mid, edge : %f, %f\n", mid, edge);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (int *)malloc(sizeof(int) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((int *)scurr->content) = (int)trunc((mid + edge - deg) * cub.img_s.width / (2 * edge));
					// printf("error1\n");
					*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_x--;
			}
			else
				light_x--;
		}
		else
		{
			curr = curr->prev;
			if (*((char *)curr->content + cub.map.px + (int)light_x) == '1')
                return (draw_so(cub, gunc, light_y, ray));
			else if (*((char *)curr->content + cub.map.px + (int)light_x) == '2')
			{
				mid = atan2((light_y + 0.5 - cub.ry), (trunc(gunc) - 0.5 - cub.rx));
				dist = hypot(light_y + 0.5 - cub.ry, trunc(gunc) - 0.5 - cub.rx);
				if (!light_x)
				{
					mid = atan2((light_y + 0.5 - cub.ry), (trunc(gunc) + 0.5 - cub.rx));
					dist = hypot(light_y + 0.5 - cub.ry, trunc(gunc) + 0.5 - cub.rx);
				}
				edge = atan(0.5 / dist);
				// printf("mid, edge : %f, %f\n", mid, edge);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (int *)malloc(sizeof(int) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((int *)scurr->content) = (int)trunc((mid + edge - deg) * cub.img_s.width / (2 * edge));
					// printf("error1\n");
					*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_y++;
			}
			else
				light_y++;
		}
	}
}

t_img shoot_a(t_cub cub, double deg, int ray)
{
	double  light_x;
	double  light_y;
	double  func;
	double  gunc;

	double	mid;
	double	edge;
	t_list	*scurr;
	double	dist;
	int	*arr;

	t_list  *curr;

	light_x = 1;
	light_y = 1;
	curr = cub.map.py;
	while (1)
	{
		func = tan(deg) * (light_x - cub.rx) + cub.ry;
		gunc = (1 / tan(deg)) * (light_y - cub.ry) + cub.rx;

		if (hypot(light_x, func) < hypot(light_y, gunc))
		{
			if (*((char *)curr->content + cub.map.px + (int)light_x) == '1')
                return (draw_we(cub, light_x, func, ray));
			else if (*((char *)curr->content + cub.map.px + (int)light_x) == '2')
			{
				mid = atan2((trunc(func) + 0.5 - cub.ry), (light_x + 0.5 - cub.rx));
				dist = hypot(trunc(func) + 0.5 - cub.ry, light_x + 0.5 - cub.rx);
				edge = atan(0.5 / dist);
				// printf("mid, edge : %f, %f\n", mid, edge);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (int *)malloc(sizeof(int) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((int *)scurr->content) = (int)trunc((mid + edge - deg) * cub.img_s.width / (2 * edge));
					// printf("error1\n");
					*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_x++;
			}
			else
				light_x++;
		}
		else
		{
			curr = curr->prev;
			if (*((char *)curr->content + cub.map.px + (int)light_x - 1) == '1')
                return (draw_so(cub, gunc, light_y, ray));
			else if (*((char *)curr->content + cub.map.px + (int)light_x - 1) == '2')
			{
				mid = atan2((light_y + 0.5 - cub.ry), (trunc(gunc) + 0.5 - cub.rx));
				dist = hypot(light_y + 0.5 - cub.ry, trunc(gunc) + 0.5 - cub.rx);
				edge = atan(0.5 / dist);
				// printf("mid, edge : %f, %f\n", mid, edge);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (int *)malloc(sizeof(int) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((int *)scurr->content) = (int)trunc((mid + edge - deg) * cub.img_s.width / (2 * edge));
				// 	printf("my position : %f, %f\n", cub.rx, cub.ry);
				// printf("mid, edge, deg : %f, %f, %f\n", mid, edge, deg);
				// 	printf("inf? %f\n", (mid + edge - deg) * cub.img_s.width / (2 * edge));
				// 	printf("inf2? %f\n", (cub.map.screen_y / (2 * dist * tan(cub.fovv / 2))));
					// printf("error\n");
					*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_y++;
			}
			else
				light_y++;
		}
	}
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
	if (cub->key.wmask == 1)
		*cub = move_forward(*cub);
	if (cub->key.amask == 1)
		*cub = move_backward(*cub);
	if (cub->key.smask == 1)
		*cub = move_left(*cub);
	if (cub->key.dmask == 1)
		*cub = move_right(*cub);
	if (cub->key.rightmask == 1)
		cub->direction -= 0.05;
	if (cub->key.leftmask == 1)
		cub->direction += 0.05;

	ray = 0;
	while (ray < cub->map.screen_x)
	{
		cub->scr = singlelight(*cub, ray);
		ray++;
	}
    mlx_put_image_to_window(cub->mlx, cub->win, cub->scr.img, 0, 0);

	return (0);
}


void    display(t_map map)
{
	t_cub cub;

	cub.map = map;
	cub = cub_init(cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, map.screen_x, map.screen_y, "레이캐스팅");

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

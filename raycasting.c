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
	cub.real_x = 0.5;
	cub.real_y = 0.5;
	// cub.spr = (t_list *)malloc(sizeof(t_list));
	// if (!cub.spr)
	// 	free_error(cub.map);
	// cub.spr->content = 0;
	// cub.spr->next = 0;
	// cub.spr->prev = 0;
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
	if (cub.win)
		mlx_destroy_window(cub.mlx, cub.win);
}

int is_xcollission(t_cub cub, double x)
{
	t_list	*curr;

	curr = cub.map.position_y;
	if (x < CR && *(CURR_WALL - 1) == '1')
		return (1);
	if (x > 1 - CR && *(CURR_WALL + 1) == '1')
		return (1);
	if (x < CR && cub.real_y < CR && *(NEXT_WALL - 1) == '1')
		return (1);
	if (x < CR && cub.real_y > 1 - CR && *(PREV_WALL - 1) == '1')
		return (1);
	if (x > 1 - CR && cub.real_y < CR && *(NEXT_WALL + 1) == '1')
		return (1);
	if (x > 1 - CR && cub.real_y > 1 - CR && *(PREV_WALL + 1) == '1')
		return (1);
	return (0);
}

int is_ycollission(t_cub cub, double y)
{
	t_list	*curr;

	curr = cub.map.position_y;
	if (y < CR && *(NEXT_WALL) == '1')
		return (1);
	if (y > 1 - CR && *(PREV_WALL) == '1')
		return (1);
	if (cub.real_x < CR && y < CR && *(NEXT_WALL - 1) == '1')
		return (1);
	if (cub.real_x < CR && y > 1 - CR && *(PREV_WALL - 1) == '1')
		return (1);
	if (cub.real_x > 1 - CR && y < CR && *(NEXT_WALL + 1) == '1')
		return (1);
	if (cub.real_x > 1 - CR && y > 1 - CR && *(PREV_WALL + 1) == '1')
		return (1);
	return (0);
}

t_cub move_forward(t_cub cub)
{
	if (!is_xcollission(cub, cub.real_x + 0.05 * cos(cub.direction)))
		cub.real_x += 0.05 * cos(cub.direction);
	if (!is_ycollission(cub, cub.real_y + 0.05 * sin(cub.direction)))
		cub.real_y += 0.05 * sin(cub.direction);
		if (cub.real_x >= 1)
		{
			cub.real_x -= 1;
			cub.map.position_x++;
		}
		else if (cub.real_x < 0)
		{
			cub.real_x += 1;
			cub.map.position_x--;
		}
		if (cub.real_y >= 1)
		{
			cub.real_y -= 1;
			cub.map.position_y = cub.map.position_y->prev;
		}
		if (cub.real_y < 0)
		{
			cub.real_y += 1;
			cub.map.position_y = cub.map.position_y->next;
		}
	return (cub);
}

t_cub move_backward(t_cub cub)
{
	if (!is_xcollission(cub, cub.real_x - 0.05 * cos(cub.direction)))
		cub.real_x -= 0.05 * cos(cub.direction);
	if (!is_ycollission(cub, cub.real_y - 0.05 * sin(cub.direction)))
		cub.real_y -= 0.05 * sin(cub.direction);
		if (cub.real_x >= 1)
		{
			cub.real_x -= 1;
			cub.map.position_x++;
		}
		else if (cub.real_x < 0)
		{
			cub.real_x += 1;
			cub.map.position_x--;
		}
		if (cub.real_y >= 1)
		{
			cub.real_y -= 1;
			cub.map.position_y = cub.map.position_y->prev;
		}
		if (cub.real_y < 0)
		{
			cub.real_y += 1;
			cub.map.position_y = cub.map.position_y->next;
		}
	return (cub);
}

t_cub move_left(t_cub cub)
{
	if (!is_xcollission(cub, cub.real_x - 0.05 * cos(cub.direction - M_PI_2)))
		cub.real_x -= 0.05 * cos(cub.direction - M_PI_2);
	if (!is_ycollission(cub, cub.real_y - 0.05 * sin(cub.direction - M_PI_2)))
		cub.real_y -= 0.05 * sin(cub.direction - M_PI_2);
		if (cub.real_x >= 1)
		{
			cub.real_x -= 1;
			cub.map.position_x++;
		}
		else if (cub.real_x < 0)
		{
			cub.real_x += 1;
			cub.map.position_x--;
		}
		if (cub.real_y >= 1)
		{
			cub.real_y -= 1;
			cub.map.position_y = cub.map.position_y->prev;
		}
		if (cub.real_y < 0)
		{
			cub.real_y += 1;
			cub.map.position_y = cub.map.position_y->next;
		}
	return (cub);
}

t_cub move_right(t_cub cub)
{
	if (!is_xcollission(cub, cub.real_x - 0.05 * cos(cub.direction + M_PI_2)))
		cub.real_x -= 0.05 * cos(cub.direction + M_PI_2);
	if (!is_ycollission(cub, cub.real_y - 0.05 * sin(cub.direction + M_PI_2)))
		cub.real_y -= 0.05 * sin(cub.direction + M_PI_2);
		if (cub.real_x >= 1)
		{
			cub.real_x -= 1;
			cub.map.position_x++;
		}
		else if (cub.real_x < 0)
		{
			cub.real_x += 1;
			cub.map.position_x--;
		}
		if (cub.real_y >= 1)
		{
			cub.real_y -= 1;
			cub.map.position_y = cub.map.position_y->prev;
		}
		if (cub.real_y < 0)
		{
			cub.real_y += 1;
			cub.map.position_y = cub.map.position_y->next;
		}
	return (cub);
}

int     key(int keycode, t_cub *cub)
{
	// printf("key : %d\n", keycode);
	if (keycode == 35)
	{
		printf("POSITION xy :	%s	of %d\n", cub->map.position_y->content, cub->map.position_x + 1);
		printf("real xy : %f, %f\n", cub->real_x, cub->real_y);
	}
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



t_cub   draw_no(t_cub cub, double deg, double x, double y)
{
    double dist;
    int wall_height;
    int wall_top;
    char *dst;
    char *srcs;
    int adr_x;
    int adr_y;
	int tmp;


    dist = hypot(x - cub.real_x, y - cub.real_y);
	dist *= cos(cub.direction - deg);
	if (x < 0)
		adr_x = trunc((x - trunc(x)) * -1 * cub.img_no.width) + 1;
	else
		adr_x = cub.img_no.width - trunc((x - trunc(x))* cub.img_no.width);
    wall_height = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
    wall_top = (cub.map.screen_y / 2) - (wall_height / 2);
    int i = -1; //나중에는 이게 진짜 세로줄 첫번째를 나타내는 지표가 될 듯. floor랑 ceiling채워야지
	while (++i < wall_top)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_ceiling;
	}
	tmp = wall_top;
    while (++i < wall_height + tmp)
    {
        adr_y = (wall_top - tmp) * cub.img_no.height / wall_height;
        dst = cub.screen.img_adrr + (wall_top * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        srcs = cub.img_no.img_adrr + (adr_y * cub.img_no.sl + adr_x * (cub.img_no.bpp / 8));
        wall_top++;
		if (wall_top <= 0 || wall_top >= cub.map.screen_y)
			continue;
        *(unsigned int *)dst = *(unsigned char *)srcs;
    }
	while (++i < cub.map.screen_y)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_floor;
		
	}
    return (cub);
}

t_cub   draw_ea(t_cub cub, double deg, double x, double y)
{
    double dist;
    int wall_height;
    int wall_top;
    char *dst;
    char *srcs;
    int adr_x;
    int adr_y;
	int tmp;

    dist = hypot(x - cub.real_x, y - cub.real_y);
	dist *= cos(cub.direction - deg);
    if (y < 0)
    	adr_x = cub.img_ea.width - trunc((y - trunc(y)) * -1 * cub.img_ea.width);
	else
    	adr_x = trunc((y - trunc(y)) * cub.img_ea.width);
    wall_height = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
    wall_top = cub.map.screen_y / 2 - (wall_height / 2);
    int i = -1;
	while (++i < wall_top)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_ceiling;
	}
	tmp = wall_top;
    while (++i < wall_height + tmp)
    {
        adr_y = (wall_top - tmp) * cub.img_ea.height / wall_height;
        dst = cub.screen.img_adrr + (wall_top * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        srcs = cub.img_ea.img_adrr + (adr_y * cub.img_ea.sl + adr_x * (cub.img_ea.bpp / 8));
        wall_top++;
		if (wall_top <= 0 || wall_top >= cub.map.screen_y)
			continue;
        *(unsigned int *)dst = *(unsigned int *)srcs;
    }
	while (++i < cub.map.screen_y)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_floor;
		
	}
    return (cub);
}

t_cub   draw_so(t_cub cub, double deg, double x, double y)
{
    double dist;
    int wall_height;
    int wall_top;
    char *dst;
    char *srcs;
    int adr_x;
    int adr_y;
	int tmp;
    
	t_list *curr;

    dist = hypot(x - cub.real_x, y - cub.real_y);
	dist *= cos(cub.direction - deg);
    if (x < 0)
    	adr_x = cub.img_so.width - trunc((x - trunc(x)) * -1 * cub.img_so.width) - 1;
	else
	    adr_x = trunc((x - trunc(x)) * cub.img_so.width);

	wall_height = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
    wall_top = cub.map.screen_y / 2 - (wall_height / 2);
    int i = -1;
	while (++i < wall_top)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_ceiling;
	}
	tmp = wall_top;
    while (++i < wall_height + tmp)
    {
        adr_y = (wall_top - tmp) * cub.img_so.height / wall_height;
        dst = cub.screen.img_adrr + (wall_top * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        srcs = cub.img_so.img_adrr + (adr_y * cub.img_so.sl + adr_x * (cub.img_so.bpp / 8));
        wall_top++;
		if (wall_top <= 0 || wall_top >= cub.map.screen_y)
			continue;
        *(unsigned int *)dst = *(unsigned int *)srcs;
    }
	while (++i < cub.map.screen_y)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_floor;
		
	}
	curr = cub.spr->next;
	int d = 0;
	if (curr)
	{
	int s_top = (cub.map.screen_y / 2) - (int)(*((double *)curr->content + 1) / 2);
		int adx = (int)trunc(*((double *)curr->content));
		while (d < (int)*((double *)curr->content + 1))
		{
			int ady = (int)(d * cub.img_s.height / *((double *)curr->content + 1));
			dst = cub.screen.img_adrr + ((s_top + d) * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
			srcs = cub.img_s.img_adrr + (ady * cub.img_s.sl + adx * (cub.img_s.bpp / 8));
			if (*(unsigned int *)srcs <= 0x00ffffff && *(unsigned int *)srcs)
				*(unsigned int *)dst = *(unsigned int *)srcs;
			d++;
		}
	}
	ft_lstclear(&cub.spr, free);
    return (cub);
}

t_cub   draw_we(t_cub cub, double deg, double x, double y)
{
    double dist;
    int wall_height;
    int wall_top;
    char *dst;
    char *srcs;
    int adr_x;
    int adr_y;
	int tmp;

	t_list *curr;


    dist = hypot(x - cub.real_x, y - cub.real_y);
	dist *= cos(cub.direction - deg);
    if (y < 0)
    	adr_x = trunc((y - trunc(y)) * -1 * cub.img_we.width);
	else
    	adr_x = cub.img_we.width - trunc((y - trunc(y)) * cub.img_we.width) -1;
    wall_height = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
    wall_top = cub.map.screen_y / 2 - (wall_height / 2);

    int i = -1;
	while (++i < wall_top)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_ceiling;
	}
	tmp = wall_top;
    while (++i < wall_height + tmp)
    {
        adr_y = (wall_top - tmp) * cub.img_we.height / wall_height;
        dst = cub.screen.img_adrr + (wall_top * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        srcs = cub.img_we.img_adrr + (adr_y * cub.img_we.sl + adr_x * (cub.img_we.bpp / 8));
        wall_top++;
		if (wall_top <= 0 || wall_top >= cub.map.screen_y)
			continue;
        *(unsigned int *)dst = *(unsigned int *)srcs;
    }
	while (++i < cub.map.screen_y)
	{
        dst = cub.screen.img_adrr + (i * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
        *(unsigned int *)dst = cub.map.c_floor;
	}
	curr = cub.spr->next;
	int d = 0;
	if (curr)
	{
	int s_top = (cub.map.screen_y / 2) - (int)(*((double *)curr->content + 1) / 2);
		int adx = (int)trunc(*((double *)curr->content));
		while (d < (int)*((double *)curr->content + 1))
		{
			int ady = (int)(d * cub.img_s.height / *((double *)curr->content + 1));
			dst = cub.screen.img_adrr + ((s_top + d) * cub.screen.sl + cub.ray_x * (cub.screen.bpp / 8));
			srcs = cub.img_s.img_adrr + (ady * cub.img_s.sl + adx * (cub.img_s.bpp / 8));
			if (*(unsigned int *)srcs <= 0x00ffffff && *(unsigned int *)srcs)
				*(unsigned int *)dst = *(unsigned int *)srcs;
			d++;
		}
	}
	ft_lstclear(&cub.spr, free);
    return (cub);
}


t_cub shoot_d(t_cub cub, double deg, char *news)
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
	double	*arr;


	light_x = 1;
	light_y = 0;

	curr = cub.map.position_y;
	while (1)
	{
		func = tan(deg) * (light_x - cub.real_x) + cub.real_y;
		gunc = (1 / tan(deg)) * (light_y - cub.real_y) + cub.real_x;

		if (hypot(light_x, func) < hypot(light_y, gunc))
		{
			if (*(POSITION + (int)light_x) == '1')
                return (draw_we(cub, deg, light_x, func));
			else
				light_x++;
		}
		else
		{
			curr = curr->next;
			if (*(POSITION + (int)light_x - 1) == '1')
                return (draw_no(cub, deg, gunc, light_y));
			else
				light_y--;
		}
	}
}

t_cub shoot_c(t_cub cub, double deg, char *news)
{
	double  light_x;
	double  light_y;
	double  func;
	double  gunc;
	t_list  *curr;

	light_x = 0;
	light_y = 0;
	curr = cub.map.position_y;
	while (1)
	{
		func = tan(deg) * (light_x - cub.real_x) + cub.real_y;
		gunc = (1 / tan(deg)) * (light_y - cub.real_y) + cub.real_x;

		if (hypot(light_x - 1, func - 1) < hypot(light_y - 1, gunc - 1))
		{
			if (*(POSITION + (int)light_x - 1) == '1')
                return (draw_ea(cub, deg, light_x, func));
			else
				light_x--;
		}
		else
		{
			curr = curr->next;
			if (*(POSITION + (int)light_x) == '1') //zzzㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
                return (draw_no(cub, deg, gunc, light_y));
			else
				light_y--;
		}
	}
}

t_cub shoot_b(t_cub cub, double deg, char *news)
{
	double  light_x;
	double  light_y;
	double  func;
	double  gunc;
	t_list  *curr;

	light_x = 0;
	light_y = 1;
	curr = cub.map.position_y;
	while (1)
	{
		func = tan(deg) * (light_x - cub.real_x) + cub.real_y;
		gunc = (1 / tan(deg)) * (light_y - cub.real_y) + cub.real_x;

		if (hypot(light_x, func) < hypot(light_y, gunc))
		{
			if (*(POSITION + (int)light_x - 1) == '1')
                return (draw_ea(cub, deg, light_x, func));
			else
				light_x--;
		}
		else
		{
			curr = curr->prev;
			if (*(POSITION + (int)light_x) == '1')
                return (draw_so(cub, deg, gunc, light_y));
			else
				light_y++;
		}
	}
}

t_cub shoot_a(t_cub cub, double deg, char *news)
{
	double  light_x;
	double  light_y;
	double  func;
	double  gunc;

	double	mid;
	double	edge;
	t_list	*scurr;
	double	dist;
	double	*arr;

	t_list  *curr;

	light_x = 1;
	light_y = 1;
	curr = cub.map.position_y;
	while (1)
	{
		func = tan(deg) * (light_x - cub.real_x) + cub.real_y;
		gunc = (1 / tan(deg)) * (light_y - cub.real_y) + cub.real_x;

		if (hypot(light_x, func) < hypot(light_y, gunc))
		{
			if (*(POSITION + (int)light_x) == '1')
                return (draw_we(cub, deg, light_x, func));
			else if (*(POSITION + (int)light_x) == '2')
			{
				mid = atan((trunc(func) + 0.5 - cub.real_y) / (light_x + 0.5 - cub.real_x));
				dist = hypot(trunc(func) + 0.5 - cub.real_y, light_x + 0.5 - cub.real_x);
				edge = atan(0.5 / dist);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (double *)malloc(sizeof(double) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((double *)scurr->content) = (mid + edge - deg) * cub.img_s.width / (2 * edge);
					*((double *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_x++;
			}
			else
				light_x++;
		}
		else
		{
			curr = curr->prev;
			if (*(POSITION + (int)light_x - 1) == '1')
                return (draw_so(cub, deg, gunc, light_y));
			else if (*(POSITION + (int)light_x - 1) == '2')
			{
				mid = atan((light_y + 0.5 - cub.real_y) / (trunc(gunc) + 0.5 - cub.real_x));
				dist = hypot(light_y + 0.5 - cub.real_y, trunc(gunc) + 0.5 - cub.real_x);
				edge = atan(0.5 / dist);
				if ((deg > mid - edge) && (deg < mid + edge))
				{
					arr = (double *)malloc(sizeof(double) * 2);
					scurr = ft_lstnew(arr);
					ft_lstadd_back(&cub.spr, scurr);
					*((double *)scurr->content) = (mid + edge - deg) * cub.img_s.width / (2 * edge);
					*((double *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * dist * tan(cub.fovv / 2)));
				}
				light_y++;
			}
			else
				light_y++;
		}
	}
}





t_cub shoot_up(t_cub cub, char *news)
{
	double  light_y;
	t_list  *curr;

	*news = 's';
	light_y = 1;
	curr = cub.map.position_y;
	while (1)
	{
		curr = curr->prev;
		if (*(POSITION) == '1')
            return (draw_so(cub, M_PI_2, cub.real_x, light_y));
		else
			light_y++;
	}
	return (cub);
}

t_cub shoot_left(t_cub cub, char *news)
{
	double  light_x;
	t_list  *curr;

	*news = 'e';
	light_x = 0;
	curr = cub.map.position_y;
	while (1)
	{
		if (*(POSITION + (int)light_x) == '1')
            return (draw_ea(cub, M_PI, light_x, cub.real_y));
		else
			light_x--;
	}
	return (cub);
}

t_cub shoot_down(t_cub cub, char *news)
{
	double  light_y;
	t_list  *curr;

	*news = 'n';
	light_y = 0;
	curr = cub.map.position_y;
	while (1)
	{
		curr = curr->next;
		if (*(POSITION) == '1')
            return (draw_no(cub, 3 * M_PI_2, cub.real_x, light_y));
		else
			light_y--;
	}
	return (cub);
}

t_cub shoot_right(t_cub cub, char *news)
{
	double  light_x;
	t_list  *curr;

	*news = 'w';
	light_x = 1;
	curr = cub.map.position_y;
	while (1)
	{
		if (*(POSITION) == '1')
            return (draw_we(cub, 0, light_x, cub.real_y));
		else
			light_x++;
	}
	return (cub);
}


t_cub singlelight(t_cub cub)
{
	double deg;
	char news;
	double dist;
	double	len;


	cub.deg = (cub.direction + cub.fovh / 2) - cub.fovh / (cub.map.screen_x - 1) * cub.ray_x;
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


    // cub.direction += 6 * M_PI_4;
    // cub.direction -= M_PI_4;
	deg = cub.deg;
    // printf("deg : %f\n", deg);
	if (deg > 0 && deg < M_PI_2)
		return (shoot_a(cub, deg, &news));
	if (deg > M_PI_2 && deg < M_PI)
		return (shoot_b(cub, deg, &news));
	if (deg > M_PI && deg < 3 * M_PI_2)
		return (shoot_c(cub, deg, &news));
	if (deg > 3 * M_PI_2 && deg < 2 * M_PI)
		return (shoot_d(cub, deg, &news));
	if (deg == M_PI_2)
		return (shoot_up(cub, &news));
	if (deg == M_PI)
		return (shoot_left(cub, &news));
	if (deg == 3 * M_PI_2)
		return (shoot_down(cub, &news));
	if (deg == 0)
		return (shoot_right(cub, &news));

//받아온 값은 정확한 거리와 벽의 방향. 추가적으로 각도 역시 가지고 있다. 각도는 나중에 휘어지는 것 방지할 때 쓰기
//이미지의 어떤 값을 참조하려는지 알기 위해서는 해당 좌표도 결국 필요하다.
	// len = 2 * dist * tan(cub.fovv / 2);
	// if (news == 'n')
	// 	cub = draw_no(cub, len);
	// if (news == 's')
	// 	cub = draw_so(cub, len);
	// if (news == 'e')
	// 	cub = draw_ea(cub, len);
	// if (news == 'w')
	// 	cub = draw_we(cub, len);
	return (cub);
}

int gogo(t_cub *cub)
{
	if (cub->key.wmask == 1)
		*cub = move_forward(*cub);
	if (cub->key.amask == 1)
		*cub = move_backward(*cub);
	if (cub->key.smask == 1)
		*cub = move_left(*cub);
	if (cub->key.dmask == 1)
		*cub = move_right(*cub);
	if (cub->key.rightmask == 1)
		cub->direction -= 0.07;
	if (cub->key.leftmask == 1)
		cub->direction += 0.07;

		cub->ray_x = 0;
	while (cub->ray_x < cub->map.screen_x)
	{
		*cub = singlelight(*cub);
		cub->ray_x++;
	}
    mlx_put_image_to_window(cub->mlx, cub->win, cub->screen.img, 0, 0);

	return (0);
}


void    display(t_map map)
{
	t_cub cub;

	cub.map = map;
	cub = cub_init(cub);
	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, map.screen_x, map.screen_y, "레이캐스팅");

	cub.screen.img = mlx_new_image(cub.mlx, map.screen_x, map.screen_y);
	cub.img_no.img = mlx_xpm_file_to_image(cub.mlx, map.i_no, &cub.img_no.width, &cub.img_no.height);
	cub.img_so.img = mlx_xpm_file_to_image(cub.mlx, map.i_so, &cub.img_so.width, &cub.img_so.height);
	cub.img_ea.img = mlx_xpm_file_to_image(cub.mlx, map.i_ea, &cub.img_ea.width, &cub.img_ea.height);
	cub.img_we.img = mlx_xpm_file_to_image(cub.mlx, map.i_we, &cub.img_we.width, &cub.img_we.height);
	cub.img_s.img = mlx_xpm_file_to_image(cub.mlx, map.i_s, &cub.img_s.width, &cub.img_s.height);

    cub.screen.img_adrr = mlx_get_data_addr(cub.screen.img, &cub.screen.bpp, &cub.screen.sl, &cub.screen.en);
	cub.img_no.img_adrr = mlx_get_data_addr(cub.img_no.img, &cub.img_no.bpp, &cub.img_no.sl, &cub.img_no.en);
	cub.img_so.img_adrr = mlx_get_data_addr(cub.img_so.img, &cub.img_so.bpp, &cub.img_so.sl, &cub.img_so.en);
	cub.img_ea.img_adrr = mlx_get_data_addr(cub.img_ea.img, &cub.img_ea.bpp, &cub.img_ea.sl, &cub.img_ea.en);
	cub.img_we.img_adrr = mlx_get_data_addr(cub.img_we.img, &cub.img_we.bpp, &cub.img_we.sl, &cub.img_we.en);
	cub.img_s.img_adrr = mlx_get_data_addr(cub.img_s.img, &cub.img_s.bpp, &cub.img_s.sl, &cub.img_s.en);

	cub.fovh = M_PI / 3; //60도 마찌??
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

	// cub.ray_x = 0;
	// while (cub.ray_x < cub.map.screen_x)
	// {
	// 	cub = singlelight(cub);
	// 	cub.ray_x++;
	// }
    // mlx_put_image_to_window(cub.mlx, cub.win, cub.screen.img, 0, 0);
	mlx_loop(cub.mlx);
}

// typedef struct s_val
// {
//     void *mlx;
//     void *win;
//     void *img;
//     int bpp;
//     int sl;
//     int en;
//     char *imad;

//     int x;
//     int y;
//     unsigned int color;

//     char *dst;
//     int i;
//     int tcl;
// }              t_val;

// int print(int key, t_val *t)
// {
//     printf("key : %d\n", key);
// }

// int rendering(t_val *t)
// {
//     t->x = 0;
//     t->y = 0;
//     while (t->x < 480)
//     {
//         while (t->y < 360)
//         {
//             t->dst = t->imad + (t->y * t->sl + t->x * (t->bpp / 8));
//             *(unsigned int*)t->dst = t->color;
//             t->y += 1;
//             // t->color += 10;
//         }
//         t->x += 1;
//         t->y = 0;
//         // t->color += 10;
//     }
//     if (t->color <= 0x000000ff)
//     {
//         t->tcl = 1;
//         t->color += t->tcl;
//     }
//     else if (t->color <= 0x0000ffff)
//     {
//         t->tcl = 0x00000100;
//         t->color += t->tcl;
//     }
//     else if (t->color <= 0x00ffffff)
//     {
//         t->tcl = 0x00010000;
//         t->color += t->tcl;
//     }
//     else
//     {
//         t->color = 0;
//     }

//     mlx_put_image_to_window(t->mlx, t->win, t->img, 120, 60);
// }
// void display(void)
// {
//     t_val t;

//     t.color = 0;
//     t.mlx = mlx_init();
// 	printf("what?\n");
//     t.win = mlx_new_window(t.mlx, 720, 480, "그림 그리기");
//     t.i = 0;
//     t.img = mlx_new_image(t.mlx, 480, 360);
//     t.imad = mlx_get_data_addr(t.img, &t.bpp, &t.sl, &t.en);
//     printf("bpp: %d, sl: %d, endian: %d\n", t.bpp, t.sl, t.en);
//     mlx_hook(t.win, 2, 1, print, &t);
//     mlx_loop_hook(t.mlx, rendering, &t);
//     mlx_loop(t.mlx);
// }

// 이미지 확대와 축소
	// cub.img_ea.img = mlx_xpm_file_to_image(cub.mlx, cub.map.i_ea, &cub.img_ea.width, &cub.img_ea.height);
	// cub.screen.img = mlx_new_image(cub.mlx, ga, se); //나중에는 창 크기에 맞춰서 크기를 잡게 되지 않을까.

	// cub.img_ea.img_adrr = mlx_get_data_addr(cub.img_ea.img, &cub.img_ea.bpp, &cub.img_ea.sl, &cub.img_ea.en);
	// cub.screen.img_adrr = mlx_get_data_addr(cub.screen.img, &cub.screen.bpp, &cub.screen.sl, &cub.screen.en);

	// int i = -1;
	// int j = -1;
	// char *dst;
	// char *srcs;
	// int x;
	// int y;
	// while (++i < ga)
	// {
	//     j = -1;
	//     while (++j < se)
	//     {
	//         x = i * cub.img_ea.width / ga;
	//         y = j * cub.img_ea.height / se;
	//         printf("so xy : %d, %d\n", x, y);
	//         dst = cub.screen.img_adrr + (j * cub.screen.sl + i * (cub.screen.bpp / 8));
	//         srcs = cub.img_ea.img_adrr + (y * cub.img_ea.sl + x * (cub.img_ea.bpp / 8));
	//         *(unsigned int *)dst = *(unsigned int *)srcs;
	//     }
	// }
	// mlx_put_image_to_window(cub.mlx, cub.win, cub.img_ea.img, 60, 60);
	// mlx_put_image_to_window(cub.mlx, cub.win, cub.screen.img, 120, 60);
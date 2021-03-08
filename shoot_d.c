#include "cub3d.h"

void	link_spr(t_cub cub)
{
	t_list *scurr;
	int	*arr;
	
	arr = (int *)malloc(sizeof(int) * 2);
	if (!arr)
		free_exit(cub);
	scurr = ft_lstnew(arr);
	if (!scurr)
	{
		free(arr);
		free_exit(cub);
	}
	ft_lstadd_back(&cub.spr, scurr);
	*((int *)scurr->content) = (int)trunc((cub.mid + cub.edge - cub.deg) * cub.img_s.width / (2 * cub.edge));
	*((int *)scurr->content + 1) = (int)(cub.map.screen_y / (2 * cub.dist * tan(cub.fovv / 2)));
}

void	d_we_spr(t_cub cub)
{
	cub.mid = atan2((trunc(cub.ft) - 0.5 - cub.real_y), (cub.vim_x + 0.5 - cub.real_x)) + 2 * M_PI;
	cub.dist = hypot(trunc(cub.ft) - 0.5 - cub.real_y, cub.vim_x + 0.5 - cub.real_x);
	if (!cub.vim_y)
		cub.mid = atan2((trunc(cub.ft) + 0.5 - cub.real_y), (cub.vim_x + 0.5 - cub.real_x)) + 2 * M_PI;
	if (!cub.vim_y)
		cub.dist = hypot(trunc(cub.ft) + 0.5 - cub.real_y, cub.vim_x + 0.5 - cub.real_x);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}

void	d_no_spr(t_cub cub)
{
	cub.mid = atan2((cub.vim_y - 0.5 - cub.real_y), (trunc(cub.gt) + 0.5 - cub.real_x)) + 2 * M_PI;
	cub.dist = hypot(cub.vim_y - 0.5 - cub.real_y, trunc(cub.gt) + 0.5 - cub.real_x);
	if (cub.real_x > 0.5 && cub.real_x < 1 && cub.vim_x == 1 && cub.vim_y == 0)
		cub.mid = atan2((cub.vim_y - 0.5 - cub.real_y), (trunc(cub.gt) + 0.5 - cub.real_x)) + 2 * M_PI;
	if (cub.real_x > 0.5 && cub.real_x < 1 && cub.vim_x == 1 && cub.vim_y == 0)
		cub.dist = hypot(cub.vim_y - 0.5 - cub.real_y, trunc(cub.gt) + 0.5 - cub.real_x);
	cub.edge = atan(0.5 / cub.dist);
	if ((cub.deg > cub.mid - cub.edge) && (cub.deg < cub.mid + cub.edge))
		link_spr(cub);
}


t_img shoot_d(t_cub cub, double deg, int ray)
{
	t_list  *curr;

	cub.vim_x = 1;
	cub.vim_y = 0;
	curr = cub.map.position_y;
	while (1)
	{
		cub.ft = tan(cub.deg) * (cub.vim_x - cub.real_x) + cub.real_y;
		cub.gt = (1 / tan(cub.deg)) * (cub.vim_y - cub.real_y) + cub.real_x;
		if (hypot(cub.vim_x - cub.real_x, cub.ft - cub.real_y) < hypot(cub.vim_y - cub.real_y, cub.gt - cub.real_x))
		{
			if (*((char *)curr->content + cub.map.position_x + cub.vim_x) == '1')
                return (draw_we(cub, cub.vim_x, cub.ft, ray));
			else if (*((char *)curr->content + cub.map.position_x + cub.vim_x) == '2')
				d_we_spr(cub);
			cub.vim_x++;
		}
		else
		{
			curr = curr->next;
			if (*((char *)curr->content + cub.map.position_x + cub.vim_x - 1) == '1')
                return (draw_no(cub, cub.gt, cub.vim_y, ray));
			else if (*((char *)curr->content + cub.map.position_x + cub.vim_x - 1) == '2')
				d_no_spr(cub);
			cub.vim_y--;
		}
	}
}
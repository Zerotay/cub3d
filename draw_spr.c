#include "cub3d.h"

t_img	single_spr(t_cub cub, int ray, t_list *curr)
{
	int		i;
	int		top;
	int		temp;

	i = -1;
	top = (cub.map.screen_y / 2) - (*((int *)curr->content + 1) / 2);
	temp = top;
	while (++i < *((int *)curr->content + 1))
	{
		cub.adr_y = (int)(i * cub.img_s.height / *((int *)curr->content + 1));
		cub.dst = top * cub.scr.sl + ray * (cub.scr.bpp / 8) + cub.scr.i_adr;
		cub.srcs = cub.adr_y * cub.img_s.sl
					+ cub.adr_x * (cub.img_s.bpp / 8) + cub.img_s.i_adr;
		if (++top < 0 || temp + i > cub.map.screen_y)
			continue;
		if (*(unsigned int *)cub.srcs <= 0x00ffffff)
			*(unsigned int *)cub.dst = *(unsigned int *)cub.srcs;
	}
	return (cub.scr);
}

t_img	draw_spr(t_cub cub, int ray)
{
	t_list	*curr;

	curr = ft_lstlast(cub.spr);
	while (curr->prev)
	{
		cub.adr_x = *((int *)curr->content);
		cub.scr = single_spr(cub, ray, curr);
		curr = curr->prev;
	}
	ft_lstclear(&cub.spr, free);
	return (cub.scr);
}

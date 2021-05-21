/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:53:48 by dongguki          #+#    #+#             */
/*   Updated: 2021/05/21 13:41:42 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	single_spr(t_cub cub, int ray, t_list *curr)
{
	int		top;
	int		temp;

	top = (cub.map.sy / 2) - (*((int *)curr->content + 1) / 2);
	temp = top;
	while (++cub.i < *((int *)curr->content + 1))
	{
		if (++top < 0 || temp + cub.i > cub.map.sy - 2)
			continue ;
		cub.ay = (cub.i * cub.img_s.height / *((int *)curr->content + 1));
		cub.dst = top * cub.scr.sl + ray * (cub.scr.bpp / 8) + cub.scr.adr;
		cub.srcs = cub.ay * cub.img_s.sl \
					 + cub.ax * (cub.img_s.bpp / 8) + cub.img_s.adr;
		// printf("dest : %p, xy : %d %d  srcs : %p xy : %d %d \n", cub.dst, ray, top, cub.srcs, cub.ax, cub.ay);
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
		cub.ax = *((int *)curr->content);
		cub.i = -1;
		cub.scr = single_spr(cub, ray, curr);
		curr = curr->prev;
	}
	ft_lstclear(&cub.spr, free);
	return (cub.scr);
}

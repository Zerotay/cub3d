/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:52 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:52 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	shoot_up(t_cub cub, int ray)
{
	double	light_y;
	t_list	*curr;

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

t_img	shoot_left(t_cub cub, int ray)
{
	double	light_x;
	t_list	*curr;

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

t_img	shoot_down(t_cub cub, int ray)
{
	double	light_y;
	t_list	*curr;

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

t_img	shoot_right(t_cub cub, int ray)
{
	double	light_x;
	t_list	*curr;

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

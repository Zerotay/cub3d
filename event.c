/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:53:59 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:00 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clientclick(t_cub *cub)
{
	free_exit(*cub);
	return (0);
}

int	keypress(int keycode, t_cub *cub)
{
	if (keycode == 53)
		free_exit(*cub);
	if (keycode == 123)
		cub->action |= L;
	if (keycode == 124)
		cub->action |= R;
	if (keycode == 13)
		cub->action |= W;
	if (keycode == 1)
		cub->action |= S;
	if (keycode == 0)
		cub->action |= A;
	if (keycode == 2)
		cub->action |= D;
	return (0);
}

int	keyrelease(int keycode, t_cub *cub)
{
	if (keycode == 123)
		cub->action ^= L;
	if (keycode == 124)
		cub->action ^= R;
	if (keycode == 13)
		cub->action ^= W;
	if (keycode == 1)
		cub->action ^= S;
	if (keycode == 0)
		cub->action ^= A;
	if (keycode == 2)
		cub->action ^= D;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:53:23 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:53:24 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_xcollission(t_cub cub, double x)
{
	t_list	*curr;

	curr = cub.map.py;
	if (x < CR && *((char *)curr->content + cub.map.px - 1) == '1')
		return (1);
	if (x > 1 - CR && *((char *)curr->content + cub.map.px + 1) == '1')
		return (1);
	if (x < CR && cub.ry < CR && \
		*((char *)curr->next->content + cub.map.px - 1) == '1')
		return (1);
	if (x < CR && cub.ry > 1 - CR && \
		*((char *)curr->prev->content + cub.map.px - 1) == '1')
		return (1);
	if (x > 1 - CR && cub.ry < CR && \
		*((char *)curr->next->content + cub.map.px + 1) == '1')
		return (1);
	if (x > 1 - CR && cub.ry > 1 - CR && \
		*((char *)curr->prev->content + cub.map.px + 1) == '1')
		return (1);
	return (0);
}

int	is_ycollission(t_cub cub, double y)
{
	t_list	*curr;

	curr = cub.map.py;
	if (y < CR && *((char *)curr->next->content + cub.map.px) == '1')
		return (1);
	if (y > 1 - CR && *((char *)curr->prev->content + cub.map.px) == '1')
		return (1);
	if (cub.rx < CR && y < CR && \
		*((char *)curr->next->content + cub.map.px - 1) == '1')
		return (1);
	if (cub.rx < CR && y > 1 - CR && \
		*((char *)curr->prev->content + cub.map.px - 1) == '1')
		return (1);
	if (cub.rx > 1 - CR && y < CR && \
		*((char *)curr->next->content + cub.map.px + 1) == '1')
		return (1);
	if (cub.rx > 1 - CR && y > 1 - CR && \
		*((char *)curr->prev->content + cub.map.px + 1) == '1')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:29 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:30 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	parse(char *gv, t_map map)
{
	int	fd;

	fd = open(gv, O_RDONLY);
	if (fd < 0)
		free_error(map);
	map = parse_type(map, fd);
	map = make_list(map, fd);
	map = parse_map(map);
	return (map);
}

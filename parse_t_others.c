/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_t_others.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:22 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:23 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	fill_r(t_map map, char *line)
{
	int	i;

	i = 1;
	if (map.t_flag & IS_R)
		free_error(map);
	map.t_flag |= IS_R;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		map.sx = map.sx * 10 + line[i++] - '0';
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		map.sy = map.sy * 10 + line[i++] - '0';
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.sx || !map.sy)
		free_error(map);
	return (map);
}

int	save_color(char *line, int *i, int *tmp, int *var)
{
	int	check;

	check = 0;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		*tmp = *tmp * 10 + line[(*i)++] - '0';
		check = 1;
	}
	if (line[*i] == ',' && check && *tmp < 256)
	{
		*var += *tmp;
		*var = *var << 8;
		*tmp = 0;
		check = 0;
		(*i)++;
	}
	return (check);
}

t_map	fill_f(t_map map, char *line)
{
	int	i;
	int	tmp;
	int	check;

	i = 1;
	tmp = 0;
	if (map.t_flag & IS_F)
		free_error(map);
	map.t_flag |= IS_F;
	while (line[i] == ' ')
		i++;
	check = save_color(line, &i, &tmp, &map.c_floor);
	check = save_color(line, &i, &tmp, &map.c_floor);
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i++] - '0';
		check = 1;
	}
	map.c_floor += tmp;
	while (line[i] == ' ')
		i++;
	if (line[i] || map.c_floor & 0xFF000000 || !check || tmp > 255)
		free_error(map);
	return (map);
}

t_map	fill_c(t_map map, char *line)
{
	int	i;
	int	tmp;
	int	check;

	i = 1;
	tmp = 0;
	if (map.t_flag & IS_C)
		free_error(map);
	map.t_flag |= IS_C;
	while (line[i] == ' ')
		i++;
	check = save_color(line, &i, &tmp, &map.c_ceiling);
	check = save_color(line, &i, &tmp, &map.c_ceiling);
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i++] - '0';
		check = 1;
	}
	map.c_ceiling += tmp;
	while (line[i] == ' ')
		i++;
	if (line[i] || map.c_ceiling & 0xFF000000 || !check || tmp > 255)
		free_error(map);
	return (map);
}

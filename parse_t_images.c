/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_t_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:20 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:20 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	fill_no(t_map map, char *line)
{
	int	i;
	int	len;

	if (map.t_flag & IS_NO)
		free_error(map);
	map.t_flag |= IS_NO;
	i = 2;
	len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i])
	{
		len++;
		i++;
	}
	map.i_no = ft_substr(line, i - len, len);
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_no || !*map.i_no)
		free_error(map);
	return (map);
}

t_map	fill_so(t_map map, char *line)
{
	int	i;
	int	len;

	if (map.t_flag & IS_SO)
		free_error(map);
	map.t_flag |= IS_SO;
	i = 2;
	len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i])
	{
		len++;
		i++;
	}
	map.i_so = ft_substr(line, i - len, len);
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_so || !*map.i_so)
		free_error(map);
	return (map);
}

t_map	fill_we(t_map map, char *line)
{
	int	i;
	int	len;

	if (map.t_flag & IS_WE)
		free_error(map);
	map.t_flag |= IS_WE;
	i = 2;
	len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i])
	{
		len++;
		i++;
	}
	map.i_we = ft_substr(line, i - len, len);
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_we || !*map.i_we)
		free_error(map);
	return (map);
}

t_map	fill_ea(t_map map, char *line)
{
	int	i;
	int	len;

	if (map.t_flag & IS_EA)
		free_error(map);
	map.t_flag |= IS_EA;
	i = 2;
	len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i])
	{
		len++;
		i++;
	}
	map.i_ea = ft_substr(line, i - len, len);
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_ea || !*map.i_ea)
		free_error(map);
	return (map);
}

t_map	fill_s(t_map map, char *line)
{
	int	i;
	int	len;

	if (map.t_flag & IS_S)
		free_error(map);
	map.t_flag |= IS_S;
	i = 1;
	len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i])
	{
		len++;
		i++;
	}
	map.i_s = ft_substr(line, i - len, len);
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_s || !*map.i_s)
		free_error(map);
	return (map);
}

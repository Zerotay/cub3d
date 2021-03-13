/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:16 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:17 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	make_list(t_map map, int fd)
{
	t_list	*tmp;
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		tmp = ft_lstnew(line);
		if (!tmp)
			free_error(map);
		ft_lstadd_back(&map.map, tmp);
		if (!ft_strset(line, "102 NEWS"))
			free_error(map);
		ret = get_next_line(fd, &line);
	}
	tmp = ft_lstnew(line);
	if (!tmp)
		free_error(map);
	ft_lstadd_back(&map.map, tmp);
	if (!ft_strset(line, "102 NEWS") || ret < 0)
		free_error(map);
	return (map);
}

void	error_if_invalid(t_map map, int i, t_list *tmp)
{
	if (!tmp->prev || !tmp->next || !tmp->prev->content)
		free_error(map);
	if (!i || *((char *)tmp->content + i - 1) == ' ' \
		 || !*((char *)tmp->content + i + 1) \
		 || *((char *)tmp->content + i + 1) == ' ')
		free_error(map);
	if ((int)ft_strlen((char *)tmp->prev->content) < i + 1 \
		 || *((char *)tmp->prev->content + i) == ' ')
		free_error(map);
	if ((int)ft_strlen((char *)tmp->next->content) < i + 1 \
		 || *((char *)tmp->next->content + i) == ' ')
		free_error(map);
}

t_map	check_map_valid(t_map map, int i, t_list *tmp)
{
	if (*((char *)tmp->content + i) == '0' \
		 || *((char *)tmp->content + i) == '2')
		error_if_invalid(map, i, tmp);
	if (*((char *)tmp->content + i) == 'N' \
		 || *((char *)tmp->content + i) == 'E' \
		 || *((char *)tmp->content + i) == 'W' \
		 || *((char *)tmp->content + i) == 'S')
	{
		if (map.m_flag)
			free_error(map);
		map.m_flag = *((char *)tmp->content + i);
		map.px = i;
		map.py = tmp;
		error_if_invalid(map, i, tmp);
	}
	return (map);
}

t_map	parse_map(t_map map)
{
	int		i;
	t_list	*tmp;

	tmp = map.map->next;
	while (tmp)
	{
		i = -1;
		while (*((char *)tmp->content + ++i))
			map = check_map_valid(map, i, tmp);
		tmp = tmp->next;
	}
	if (!map.m_flag)
		free_error(map);
	return (map);
}

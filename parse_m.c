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
	return(map);
}

void	error_if_invalid(t_map map, int i, t_list *tmp)
{
	if (!tmp->prev || !tmp->next || !tmp->prev->content)
		free_error(map);
	if (!i || *(CURR + i - 1) == ' ' || !*(CURR + i + 1) || *(CURR + i + 1) == ' ')
		free_error(map);
	if ((int)ft_strlen(PREV) < i + 1 || *(PREV + i) == ' ')
		free_error(map);
	if ((int)ft_strlen(NEXT) < i + 1 || *(NEXT + i) == ' ')
		free_error(map);
}

t_map	check_map_valid(t_map map, int i, t_list *tmp)
{
	if (*(CURR + i) == '0' || *(CURR + i) == '2')
		error_if_invalid(map, i, tmp);
	if (*(CURR + i) == 'N' || *(CURR + i) == 'E' || *(CURR + i) == 'W' || *(CURR + i) == 'S')
	{
		if (map.m_flag)
			free_error(map);
		map.m_flag = *(CURR + i);
		map.position_x = i;
		map.position_y = tmp;
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
		while (*(CURR + ++i))
			map = check_map_valid(map, i, tmp);
		tmp = tmp->next;
	}
	if (!map.m_flag)
		free_error(map);
	return (map);
}

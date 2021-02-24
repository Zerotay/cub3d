#include "cub3d.h"

t_map	make_list(t_map map, int fd)
{
	t_list	*tmp;
	char	*line;
	int		ret;

	while (get_next_line(fd, &line))
	{
		ret = get_next_line(fd, &line);
		tmp = ft_lstnew(line);
		if (!tmp || ret < 0)
			free_error(map);
		ft_lstadd_back(&map.map, tmp);
		if (!ft_strset(line, "102 NEWS"))
			free_error(map);
	}
	tmp = ft_lstnew(line);
	if (!tmp || ret < 0)
		free_error(map);
	ft_lstadd_back(&map.map, tmp);
	if (!ft_strset(line, "102 NEWS"))
		free_error(map);
	return(map);
}

void	error_if_invalid(t_map map, int i, t_list *tmp)
{
	if (!tmp->prev || !tmp->next || !tmp->prev->content)
		free_error(map);
	if (!i || *(CURR + i - 1) == ' ' || !*(CURR + i + 1) || *(CURR + i + 1) == ' ')
		free_error(map);
	if (ft_strlen(PREV) < i + 1 || *(PREV + i) == ' ')
		free_error(map);
	if (ft_strlen(NEXT) < i + 1 || *(NEXT + i) == ' ')
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

void	parse_map(t_map map)
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
}

#include "cub3d.h"

t_map	check_type(t_map map, char *line)
{
	if (line[0] == 'R')
		return (fill_r(map, line));
	if (line[0] == 'N' && line[1] == 'O')
		return (fill_no(map, line));
	if (line[0] == 'S' && line[1] == 'O')
		return (fill_so(map, line));
	if (line[0] == 'W' && line[1] == 'E')
		return (fill_we(map, line));
	if (line[0] == 'E' && line[1] == 'A')
		return (fill_ea(map, line));
	if (line[0] == 'S')
		return (fill_s(map, line));
	if (line[0] == 'F')
		return (fill_f(map, line));
	if (line[0] == 'C')
		return (fill_c(map, line));
	if (line[0] == '\0')
		return (map);
	free_error(map);
	return (map);
}

t_map	parse_type(t_map map, int fd)
{
	char	*line;
	int		ret;

	while (map.t_flag != T_OK)
	{
		ret = get_next_line(fd, &line);
		if (ret <= 0)
		{
			free(line);
			free_error(map);
		}
		map = check_type(map, line);
		free(line);
	}
	return (map);
}

#include "cub3d.h"




t_map     parse(char *gv, t_map map)
{
	int fd;

	// map = map_init(map);
	fd = open(gv, O_RDONLY);
	if (fd < 0)
		free_error(map);
	map = parse_type(map, fd);
	map = make_list(map, fd);
	map = parse_map(map);
	return (map);
}
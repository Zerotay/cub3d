#include "cub3d.h"

t_map   map_init(t_map map)
{
	map.t_flag = 0;
	map.i_no = 0;
	map.i_so = 0;
	map.i_ea = 0;
	map.i_we = 0;
	map.i_s = 0;
	map.c_ceiling = 0xFFFF0000;
	map.c_floor = 0xFFFF0000;
	map.screen_x = 0;
	map.screen_y = 0;
	map.err = 0;
	map.m_flag = 0;
	map.map = (t_list *)malloc(sizeof(t_list));
	if (!map.map)
		free_error(map);
	map.map->content = 0;
	map.map->next = 0;
	map.map->prev = 0;
	map.position_x = 0;
	map.position_y = 0;
	return (map);
}

int		free_error(t_map map)
{
	printf("Error\n");
	free_all(map);
	exit(0);
}

t_map     parse(char *gv, t_map map)
{
	int fd;

	fd = open(gv, O_RDONLY);
	if (fd < 0)
		free_error(map);
	map = map_init(map);
	map = parse_type(map, fd);
	map = make_list(map, fd);
	parse_map(map);
	printf("map parsing success!!!!!!!!\n");
	return (map);
}
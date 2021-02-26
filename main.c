#include "cub3d.h"

void	free_all(t_map map)
{
	if (map.i_so)
		free(map.i_so);
	if (map.i_no)
		free(map.i_no);
	if (map.i_we)
		free(map.i_we);
	if (map.i_ea)
		free(map.i_ea);
	if (map.i_s)
		free(map.i_s);
	if (map.map)
		ft_lstclear(&map.map, free);
}

int main(int gc, char **gv)
{
	t_map map;

	if (gc == 3 && !ft_strncmp(gv[2], "--save", 6))
	{
		printf("wait for making\n");
		return (0);
	}
	else if (gc != 2 || ft_strncmp((gv[1] + ft_strlen(gv[1]) - 4), ".cub", 4))
	{
		printf("Error\n: not valid arguments\n");
		return (0);
	}
	else
	{
		map = parse(gv[1], map);
		display(map);
		free_all(map);
	}
	return (0);
}

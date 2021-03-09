#include "cub3d.h"

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
		free_map(map);
	}
	return (0);
}

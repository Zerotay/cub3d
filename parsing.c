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
	return (map);
}

t_map   its_error(t_map map)
{
	map.err = 1;
	return (map);
}

t_map   fill_r(t_map map, char *line)
{
	int i;

	i = 1;
	if (map.t_flag & R)
		return (its_error(map));
	map.t_flag |= R;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		map.screen_x = map.screen_x * 10 + line[i] - '0';
		i++;
	}
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		map.screen_y = map.screen_y * 10 + line[i] - '0';
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.screen_y)
		return (its_error(map));
	return (map);
}

t_map   fill_no(t_map map, char *line)
{
	int     i;
	int     len;
	int     start;

	if (map.t_flag & NO)
		return (its_error(map));
	map.t_flag |= NO;
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
	if (!map.i_no || !*map.i_no)
		return (its_error(map));
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_no)
		return (its_error(map));
	return (map);
}

t_map   fill_so(t_map map, char *line)
{
	int     i;
	int     len;
	int     start;

	if (map.t_flag & SO)
		return (its_error(map));
	map.t_flag |= SO;
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
	if (!map.i_so || !*map.i_so)
		return (its_error(map));
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_so)
		return (its_error(map));
	return (map);
}

t_map   fill_we(t_map map, char *line)
{
	int     i;
	int     len;
	int     start;

	if (map.t_flag & WE)
		return (its_error(map));
	map.t_flag |= WE;
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
	if (!map.i_we || !*map.i_we)
		return (its_error(map));
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_we)
		return (its_error(map));
	return (map);
}

t_map   fill_ea(t_map map, char *line)
{
	int     i;
	int     len;
	int     start;

	if (map.t_flag & EA)
		return (its_error(map));
	map.t_flag |= EA;
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
	if (!map.i_ea || !*map.i_ea)
		return (its_error(map));
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_ea)
		return (its_error(map));
	return (map);
}

t_map   fill_s(t_map map, char *line)
{
	int     i;
	int     len;
	int     start;

	if (map.t_flag & S)
		return (its_error(map));
	map.t_flag |= S;
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
	if (!map.i_s || !*map.i_s)
		return (its_error(map));
	while (line[i] == ' ')
		i++;
	if (line[i] || !map.i_s)
		return (its_error(map));
	return (map);
}
// 아예 값이 들어오지 않았을 때 처리해야 한다.
t_map	fill_f(t_map map, char *line)
{
	int	i;
	int tmp;
	int check;

	i = 1;
	tmp = 0;
	if (map.t_flag & F)
		return (its_error(map));
	map.t_flag |= F;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i] - '0';
		i++;
		check = 1;
	}
	if (line[i] == ',' && check == 1 && tmp < 256)
	{
		map.c_floor += tmp;
		map.c_floor = map.c_floor << 8;
		tmp = 0;
		check = 0;
		i++;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i] - '0';
		i++;
		check = 1;
	}
	if (line[i] == ',' && check == 1 && tmp < 256)
	{
		map.c_floor += tmp;
		map.c_floor = map.c_floor << 8;
		tmp = 0;
		check = 0;
		i++;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i] - '0';
		i++;
		check = 1;
	}
	map.c_floor += tmp;
	while (line[i] == ' ')
		i++;
	if (line[i] || map.c_floor & 0xFF000000 || !check || tmp > 255)
		return (its_error(map));
	return (map);
}

t_map	fill_c(t_map map, char *line)
{
	int	i;
	int tmp;

	i = 1;
	tmp = 0;
	if (map.t_flag & C)
		return (its_error(map));
	map.t_flag |= C;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i] - '0';
		i++;
	}
	map.c_ceiling += tmp;
	map.c_ceiling = map.c_ceiling << 8;
	tmp = 0;
	if (line[i] == ',')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i] - '0';
		i++;
	}
	map.c_ceiling += tmp;
	map.c_ceiling = map.c_ceiling << 8;
	tmp = 0;
	if (line[i] == ',')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		tmp = tmp * 10 + line[i] - '0';
		i++;
	}
	map.c_ceiling += tmp;
	while (line[i] == ' ')
		i++;
	if (line[i])
		return (its_error(map));
	return (map);
}

t_map   check_type(t_map map, char *line)
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
	// if (line[0] == ' ')
	//     return (stay(map));
	if (line[0] == '\n')
		return (map);
	// return (its_error(map));
	return (map);
	
	
		// int i;

	// char check;

	// i = 0;
	// check = line[0];
	// while (line[i])
	// {
	//     if (line[i] == 'R')
	//         map.t_flag |= R;
	//     else if (line[i] == '')
	//     i++;
	// }
}

int     parse(char *gv, t_map map)
{
	int fd;
	char *line;
	int i = 0;

	if (!(fd = open(gv, O_RDWR)))
		return (-1);
	map = map_init(map);
	while (get_next_line(fd, &line))
	{
		map = check_type(map, line);
	}
	printf("x,y is %d, %d\n", map.screen_x, map.screen_y);
	printf("NO : %s\n", map.i_no);
	printf("SO : %s\n", map.i_so);
	printf("WE : %s\n", map.i_we);
	printf("EA : %s\n", map.i_ea);
	printf("S : %s\n", map.i_s);
	printf("F : %d,%d,%d\n", map.c_floor >> 16, (map.c_floor >> 8) & 255, map.c_floor & 255);
	printf("C : %d,%d,%d\n", map.c_ceiling >> 16, (map.c_ceiling >> 8) & 255, map.c_ceiling & 255);
	printf("t_flag : %d\n", map.t_flag);
	free(map.i_no);
	free(map.i_so);
	free(map.i_we);
	free(map.i_ea);
	free(map.i_s);
	if (map.err)
	{
		printf("Error\n: this is because of errrrrrrrrrrrrrrrr\n");
		return (0);
	}
	if (map.t_flag != T_OK)
	{
		printf("Error\n: not enough type identifier\n");
		return (0);   
	}
	printf("Success!\n");
	return (0);
}
#include "cub3d.h"

void	set(unsigned char *header, int value)
{
	header[0] = (unsigned char)(value);
	header[1] = (unsigned char)(value >> 8);
	header[2] = (unsigned char)(value >> 16);
	header[3] = (unsigned char)(value >> 24);
}

int	get_color(t_cub cub, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int *)(cub.scr.adr + (y * cub.scr.sl + x * (cub.scr.bpp / 8)));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

int	set_header(t_cub cub, int fd, int pad)
{
	unsigned char	header[54];
	int				size;
	int				i;

	size = 3 * (cub.map.sx + pad) * cub.map.sy;
	i = -1;
	while (++i < 54)
		header[i] = 0;
	header[0] = 'B';
	header[1] = 'M';
	set(header + 2, size + 54);
	header[10] = 54;
	header[14] = 40;
	set(header + 18, cub.map.sx);
	set(header + 22, -1 * cub.map.sy);
	header[27] = 1;
	header[28] = 24;
	write(fd, header, 54);
	return (0);
}

int	draw_bmp(t_cub cub, int fd, int pad)
{
	int	i;
	int	j;
	int	endian;

	j = -1;
	while (++j < cub.map.sy)
	{
		i = -1;
		while (++i < cub.map.sx)
		{
			endian = get_color(cub, i, j);
			write(fd, &endian, 3);
		}
		i = -1;
		while (++i < pad)
			write(fd, "\0", 1);
	}
	return (0);
}

int	make_bmp(char *gv)
{
	t_cub	cub;
	int		pad;
	int		fd;

	cub.map.t_flag = 0;
	cub.map = map_init(cub.map);
	cub.map = parse(gv, cub.map);
	cub = cub_setting(cub);
	cub.i = -1;
	while (++cub.i < cub.map.sx)
		cub.scr = singlelight(cub, cub.i);
	fd = open("save.bmp", O_RDWR | O_CREAT | O_TRUNC, 0755);
	pad = (4 - ((3 * cub.map.sx) % 4)) % 4;
	set_header(cub, fd, pad);
	draw_bmp(cub, fd, pad);
	free_exit(cub);
	return (0);
}

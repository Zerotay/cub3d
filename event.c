#include "cub3d.h"

int	clientclick(t_cub *cub)
{
	free_exit(*cub);
	return (0);
}

int	keypress(int keycode, t_cub *cub)
{
	if (keycode == 53)
		free_exit(*cub);
	if (keycode == 123)
		cub->action |= L;
	if (keycode == 124)
		cub->action |= R;
	if (keycode == 13)
		cub->action |= W;
	if (keycode == 1)
		cub->action |= S;
	if (keycode == 0)
		cub->action |= A;
	if (keycode == 2)
		cub->action |= D;
	return (0);
}

int	keyrelease(int keycode, t_cub *cub)
{
	if (keycode == 123)
		cub->action ^= L;
	if (keycode == 124)
		cub->action ^= R;
	if (keycode == 13)
		cub->action ^= W;
	if (keycode == 1)
		cub->action ^= S;
	if (keycode == 0)
		cub->action ^= A;
	if (keycode == 2)
		cub->action ^= D;
	return (0);
}

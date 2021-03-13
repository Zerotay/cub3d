/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fuction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongguki <dongguki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:54:02 by dongguki          #+#    #+#             */
/*   Updated: 2021/03/13 11:54:03 by dongguki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_cub cub)
{
	if (cub.img_ea.img)
		mlx_destroy_image(cub.mlx, cub.img_ea.img);
	if (cub.img_no.img)
		mlx_destroy_image(cub.mlx, cub.img_no.img);
	if (cub.img_s.img)
		mlx_destroy_image(cub.mlx, cub.img_s.img);
	if (cub.img_so.img)
		mlx_destroy_image(cub.mlx, cub.img_so.img);
	if (cub.img_we.img)
		mlx_destroy_image(cub.mlx, cub.img_we.img);
	if (cub.scr.img)
		mlx_destroy_image(cub.mlx, cub.scr.img);
	if (cub.win)
		mlx_destroy_window(cub.mlx, cub.win);
}

void	free_exit(t_cub cub)
{
	free_map(cub.map);
	free_mlx(cub);
	exit(0);
}

void	free_map(t_map map)
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
	map.i_so = 0;
	map.i_ea = 0;
	map.i_s = 0;
	map.i_no = 0;
	map.i_we = 0;
}

int	free_error(t_map map)
{
	printf("Error\n");
	free_map(map);
	exit(0);
}

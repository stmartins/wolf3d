/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:55:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/19 20:00:00 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
int			get_map(int x, int y)
{
	static int	map[MAP_X][MAP_Y] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 2},
		{3, 3, 3, 3, 3, 3, 3, 2}
	};
	return (map[x][y]);
}

void		call_f(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "WOLF42");
	e->img.i = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	init_texture(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, 2, 1L << 0, key_hook, e);
	mlx_hook(e->win, DESTROYNOTIFY, STRUCT_NOT_MASK, destroy_win, e);
	e->img.data = mlx_get_data_addr(e->img.i, &(e->img.bpp), &(e->img.szline),
			&(e->img.endian));
	mlx_loop(e->mlx);
}

int			main(void)
{
	static t_env	e;

	e.p.posx = 6;
	e.p.posy = 2;
	e.p.dirx = -1;
	e.p.diry = 0;
	e.p.planex = 0;
	e.p.planey = 0.66;
	call_f(&e);
	return (0);
}
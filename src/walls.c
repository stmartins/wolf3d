/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:51:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/13 15:00:48 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void		change_wall_color(t_env *e)
{
	e->c.r /= 2;
	e->c.g /= 2;
	e->c.b /= 2;
}

void		wall_color(t_env *e, int x, int y)
{
	if (get_map(x, y) == 1)
		e->c.r = 0xff0000;
	if (get_map(x, y) == 2)
		e->c.r = 0x00ff00;
	if (get_map(x, y) == 3)
		e->c.r = 0x0000ff;
	if (get_map(x, y) == 4)
		e->c.r = 0xf0f0f0;
	/*if (get_map(x, y) == 1)
	{
		e->c.r = 0xFF;
		e->c.g = 0x00;
		e->c.b = 0x00;
	}
	else if (get_map(x, y) == 2)
	{
		e->c.r = 0x00;
		e->c.g = 0xFF;
		e->c.b = 0x00;
	}
	else if (get_map(x, y) == 3)
	{
		e->c.r = 0x00;
		e->c.g = 0x00;
		e->c.b = 0xFF;
	}
	else if (get_map(x, y) == 4)
	{
		e->c.r = 0x0f;
		e->c.g = 0x0f;
		e->c.b = 0x0f;
	}
	e->p.wallsens == 1 ? change_wall_color(e) : 1;*/
}

void		wall_h(t_env *e)
{
	int			drawstart;
	int			drawend;

	if (e->p.wallsens == 0)
		e->p.wall_len = fabs((e->p.mapx - e->p.rayposx + (1 - e->p.etapex) / 2)
				/ e->p.raydirx);
	else
		e->p.wall_len = fabs((e->p.mapy - e->p.rayposy + (1 - e->p.etapey) / 2)
				/ e->p.raydiry);
	e->p.wall_high = abs((int)(WIN_Y / e->p.wall_len));
	//printf("%d %d\n", e->p.mapx, e->p.mapy);
	drawstart = -e->p.wall_high / 2 + WIN_Y / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = e->p.wall_high / 2 + WIN_Y / 2;
	if (drawend >= WIN_Y)
		drawend = WIN_Y - 1;
	wall_color(e, e->p.mapx, e->p.mapy);
	verline(e->p.x, drawstart, drawend, e);
	/*image_put_pixel(&(e->img), drawstart, drawend,
			colorrgb(e->c.r, e->c.g, e->c.b));*/
}

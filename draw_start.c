/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:51:48 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:51:54 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_lines(t_fdf *fdf, int x, int y)
{
	int		int_xy_x1y1[4];

	int_xy_x1y1[1] = fdf->s_y + fdf->dp_int[y / fdf->n_y]\
		[x / fdf->n_x] * fdf->z + x + y;
	int_xy_x1y1[0] = fdf->s_x + (x - y);
	if (x / fdf->n_x < fdf->width - 1 && y / fdf->n_y < fdf->hight)
		draw_horizont(fdf, x, y, int_xy_x1y1);
	if (y / fdf->n_y < fdf->hight - 1 && x / fdf->n_x < fdf->width)
		draw_vertical(fdf, x, y, int_xy_x1y1);
}

void		map_draw(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	start_algoritm(fdf);
	while (x / fdf->n_x < fdf->width || y / fdf->n_y < fdf->hight - 1)
	{
		if (x / fdf->n_x == fdf->width)
		{
			x = 0;
			y += fdf->n_y;
		}
		draw_lines(fdf, x, y);
		x += fdf->n_x;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hor_ver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:51:48 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:51:54 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_horizont(t_fdf *fdf, int x, int y, int *int_xy_x1y1)
{
	int_xy_x1y1[3] = fdf->s_y + fdf->dp_int[y / fdf->n_y]\
		[x / fdf->n_x + 1] * fdf->z + (x + fdf->n_x) + y;
	int_xy_x1y1[2] = fdf->s_x + ((x + fdf->n_x) - y);
	line(fdf, int_xy_x1y1);
}

void		draw_vertical(t_fdf *fdf, int x, int y, int *int_xy_x1y1)
{
	int_xy_x1y1[3] = fdf->s_y + fdf->dp_int[y / fdf->n_y + 1]\
		[x / fdf->n_x] * fdf->z + x + (y + fdf->n_y);
	int_xy_x1y1[2] = fdf->s_x + (x - (y + fdf->n_y));
	line(fdf, int_xy_x1y1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 20:10:43 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:52:14 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_algoritm(t_fdf *fdf)
{
	if (fdf->num == 1)
	{
		fdf->z = -7;
		fdf->s_x = (1560 - 150) / 2;
		fdf->s_y = 100;
		fdf->n_x = ((1560) / 2) / (fdf->width + 10);
		fdf->n_y = ((1240) / 2) / (fdf->hight + 10);
	}
	fdf->num = 0;
}

void	line(t_fdf *win, int *x_y_x1_x2)
{
	int	length_x_y[5];

	length_x_y[0] = abs(x_y_x1_x2[2] - x_y_x1_x2[0]);
	length_x_y[1] = abs(x_y_x1_x2[3] - x_y_x1_x2[1]);
	length_x_y[2] = fmax(length_x_y[0], length_x_y[1]);
	length_x_y[3] = (x_y_x1_x2[2] - x_y_x1_x2[0] >= 0 ? 1 : -1);
	length_x_y[4] = (x_y_x1_x2[3] - x_y_x1_x2[1] >= 0 ? 1 : -1);
	if (length_x_y[2] == 0)
		mlx_pixel_put(win->mlx, win->win, \
			x_y_x1_x2[0], x_y_x1_x2[1], 0x00ffae);
	if (length_x_y[1] <= length_x_y[0])
		line_cont(win, x_y_x1_x2, length_x_y);
	else
		line_cont_next(win, x_y_x1_x2, length_x_y);
}

void	line_cont(t_fdf *win, int *x_y_x1_x2, int *length_x_y)
{
	int x;
	int y;
	int count;

	x = x_y_x1_x2[0];
	y = x_y_x1_x2[1];
	count = -length_x_y[0];
	length_x_y[2]++;
	while (length_x_y[2]--)
	{
		mlx_pixel_put(win->mlx, win->win, x, y, 0x00ffae);
		x += length_x_y[3];
		count += 2 * length_x_y[1];
		if (count > 0)
		{
			count -= 2 * length_x_y[0];
			y += length_x_y[4];
		}
	}
}

void	line_cont_next(t_fdf *win, int *x_y_x1_x2, int *length_x_y)
{
	int x;
	int y;
	int count;

	x = x_y_x1_x2[0];
	y = x_y_x1_x2[1];
	count = -length_x_y[1];
	length_x_y[2]++;
	while (length_x_y[2]--)
	{
		mlx_pixel_put(win->mlx, win->win, x, y, 0x00ffae);
		y += length_x_y[4];
		count += 2 * length_x_y[0];
		if (count > 0)
		{
			count -= 2 * length_x_y[1];
			x += length_x_y[3];
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:49:53 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:50:01 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int				esc_keypress(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(1);
	}
	return (1);
}

void			window_start(t_fdf *fdf, char *argv)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1560, 1240, argv);
	map_draw(fdf);
	mlx_key_hook(fdf->win, esc_keypress, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, exit_x, NULL);
	mlx_loop(fdf->mlx);
}

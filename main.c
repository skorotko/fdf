/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:50:53 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:50:59 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			struct_add(t_fdf *fdf)
{
	fdf->s_x = 0;
	fdf->s_y = 0;
	fdf->n_x = 0;
	fdf->n_y = 0;
	fdf->num = 1;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->dp_int = NULL;
	fdf->width = 0;
	fdf->hight = 0;
	fdf->z = 0;
}

void			fdf_check(t_fdf *fdf, int fd)
{
	char	*line;
	int		i;
	int		read_bytes;

	i = 0;
	fdf->hight = 0;
	while ((read_bytes = get_next_line(fd, &line)) > 0)
	{
		check_error(line, fdf);
		free(line);
		i++;
		fdf->hight = i;
	}
	if (!(fdf->dp_int = (int**)malloc(sizeof(int*) * (i))))
		error_output_massage("Error\n");
}

int				main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf) * 1)))
		return (0);
	struct_add(fdf);
	err_on_wrong_fd(argv[1], argc, fdf);
	fd = open(argv[1], O_RDONLY);
	read_file(fdf, fd);
	window_start(fdf, argv[1]);
	free_struct(fdf);
	close(fd);
	return (0);
}

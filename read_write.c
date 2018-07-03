/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:50:23 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:50:30 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		write_coor_int_arr(t_fdf *fdf, char **line)
{
	int			j;
	static int	i;

	j = -1;
	if ((fdf->dp_int[i] = malloc(sizeof(int) * fdf->width + 1)) == NULL)
		error_output_massage("Error\n");
	while (line[++j])
		fdf->dp_int[i][j] = ft_atoi(line[j]);
	if (line != NULL)
		ft_free(line);
	i += 1;
}

void		read_file(t_fdf *fdf, int fd)
{
	char		*line;
	int			i;

	i = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (i == -1)
			error_output_massage("Error\n");
		if (ft_isdigit(line[0]) == 0 && line[0] != ' ')
		{
			if (ft_isdigit(line[1]) == 0)
				error_output_massage("Error\n");
		}
		write_coor_int_arr(fdf, ft_strsplit(line, ' '));
		free(line);
	}
}

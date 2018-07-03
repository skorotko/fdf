/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:52:30 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/28 11:52:34 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		err_on_wrong_fd(char *argv, int argc, t_fdf *fdf)
{
	int		fd;

	if (argc != 2)
		error_output_massage("Error!\n");
	fd = open(argv, O_DIRECTORY);
	if (fd >= 0)
		error_output_massage("Error!\n");
	fd = open(argv, O_RDONLY);
	if (fd <= 0)
		error_output_massage("Error!\n");
	else
		fdf_check(fdf, fd);
	close(fd);
}

void		error_output_massage(char *str)
{
	if (str == NULL)
		return ;
	write(2, str, ft_strlen(str));
	exit(1);
}

void		check_error(char *line, t_fdf *fdf)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
		i++;
	if (fdf->hight == 0)
		fdf->width = i;
	if (i != fdf->width)
		error_output_massage("Error\n");
	ft_free(split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:28:47 by skorotko          #+#    #+#             */
/*   Updated: 2018/03/27 14:28:49 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		free_struct(t_fdf *fdf)
{
	int i;

	i = 0;
	if (fdf->dp_int != NULL)
		while (i < fdf->hight)
		{
			free(fdf->dp_int[i]);
			i++;
		}
	free(fdf);
}

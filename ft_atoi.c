/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:04:26 by skorotko          #+#    #+#             */
/*   Updated: 2017/11/21 14:37:23 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					negative;
	unsigned long int	nb;

	i = 0;
	nb = 0;
	negative = 1;
	while ((str[i] == ' ') || (str[i] == '\r') || (str[i] == '\n') ||
			(str[i] == '\t') || (str[i] == '\f') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb >= 9223372036854775807 && negative == 1)
			return (-1);
		else if (nb > 9223372036854775807 && negative == -1)
			return (0);
		i++;
	}
	return ((int)(nb * negative));
}

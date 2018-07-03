/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:54:34 by skorotko          #+#    #+#             */
/*   Updated: 2017/11/20 12:24:56 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			len_w(const char *s, char c)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		a++;
	}
	return (a);
}

static int			count_w(const char *s, char c)
{
	int i;
	int w_counter;
	int nb_of_word;

	i = 0;
	w_counter = 0;
	nb_of_word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			nb_of_word = 1;
			i++;
		}
		if (nb_of_word == 1)
			w_counter++;
		nb_of_word = 0;
	}
	return (w_counter);
}

char				**ft_strsplit(char const *s, char c)
{
	char	*arr_with_word;
	char	**num_of_dp_int;
	int		i;
	int		w_in;
	int		w_count;

	i = 0;
	w_in = 0;
	w_count = count_w(s, c);
	if (!(num_of_dp_int = (char **)malloc(sizeof(char *) * (w_count + 1))))
		return (NULL);
	while (w_in < w_count)
	{
		if (!(arr_with_word = (char*)malloc(sizeof(char) * (len_w(s, c) + 1))))
			return (NULL);
		while ((s[0] == c) && s[0] != '\0')
			s++;
		while (!(s[0] == c) && s[0] != '\0')
			arr_with_word[i++] = *s++;
		arr_with_word[i] = '\0';
		num_of_dp_int[w_in++] = arr_with_word;
		i = 0;
	}
	num_of_dp_int[w_count] = 0;
	return (num_of_dp_int);
}

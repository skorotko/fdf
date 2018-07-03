/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:40:34 by skorotko          #+#    #+#             */
/*   Updated: 2017/12/11 18:40:42 by skorotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_gnl	*add_list(t_gnl *n)
{
	n = (t_gnl*)malloc(sizeof(t_gnl));
	if (n == NULL)
		return (NULL);
	n->buf = NULL;
	return (n);
}

char	*ft_strjoine(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (strdup(s2));
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char*)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int		search(char **line, t_gnl *list)
{
	char	*e;
	char	*s;

	s = NULL;
	e = strchr(list->buf, '\n');
	if (e != NULL)
	{
		*e = '\0';
		s = list->buf;
		*line = strdup(list->buf);
		list->buf = strdup(e + 1);
		free(s);
		return (1);
	}
	if (0 < strlen((list->buf)))
	{
		*line = strdup(list->buf);
		*list->buf = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t				read_bytes;
	char				buffer[BUFF_SIZE + 1];
	static t_gnl		*begin[4864];

	if (line == NULL || (fd < 0 && fd > 4864) || BUFF_SIZE <= 0 \
		|| read(fd, NULL, 0) == -1)
		return (-1);
	if (begin[fd] == NULL)
		begin[fd] = add_list(begin[fd]);
	*line = 0;
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		begin[fd]->buf = ft_strjoine(begin[fd]->buf, buffer);
	}
	if (read_bytes < 0)
		return (-1);
	return (search(line, begin[fd]));
}

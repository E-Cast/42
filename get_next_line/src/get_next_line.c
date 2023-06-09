/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 06:47:01 by ecastong          #+#    #+#             */
/*   Updated: 2023/06/08 21:03:18 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	st_make_line(int fd, char ***line, char *src)
{
	ssize_t	i;

	**line = ft_calloc(ft_strlen(src) + BUFFER_SIZE + 1, sizeof(char));
	if (!**line)
		return (-1);
	i = 0;
	while (src[i] != '\0')
	{
		(**line)[i] = src[i];
		i++;
	}
	if (!ft_strchr(**line, '\n'))
		i = read(fd, **line + ft_strlen(**line), BUFFER_SIZE);
	if (i == -1 || ft_strlen(**line) == 0)
	{
		free (**line);
		i = -1;
	}
	return (i);
}

static void	st_make_stash(char *line, char *stash)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (line[i] != '\n')
		i++;
	j = 0;
	while (line[++i] != '\0')
	{
		stash[j++] = line[i];
		line[i] = '\0';
	}
}

static ssize_t	st_relay(int fd, char **line, char *stash)
{
	char	*tmp;
	ssize_t	i;

	if (!*line)
	{
		i = st_make_line(fd, &line, stash);
		ft_bzero(stash, BUFFER_SIZE);
	}
	else
	{
		tmp = *line;
		i = st_make_line(fd, &line, tmp);
		free (tmp);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*line;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		i = st_relay(fd, &line, stash);
		if (i == -1)
			return (NULL);
		if (i == 0)
			return (line);
		if (ft_strchr(line, '\n'))
			st_make_stash(line, stash);
	}
	return (line);
}

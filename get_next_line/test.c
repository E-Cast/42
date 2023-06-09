/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 03:33:37 by ecastong          #+#    #+#             */
/*   Updated: 2023/06/08 21:00:35 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "src/get_next_line.h"

// ssize_t	make_line(int fd, char ***line, char *src)
// {
// 	ssize_t	i;

// 	**line = ft_calloc(ft_strlen(src) + BUFF_SIZE + 1, sizeof(char));
// 	if (!**line)
// 		return (-1);
// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		(**line)[i] = src[i];
// 		i++;
// 	}
// 	if (!ft_strchr(**line, '\n'))
// 		i = read(fd, **line + ft_strlen(**line), BUFF_SIZE);
// 	if (i == -1 || ft_strlen(**line) == 0)
// 	{
// 		free (**line);
// 		i = -1;
// 	}
// 	return (i);
// }

// void	make_stash(char *line, char *stash)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (line[i] != '\n')
// 		i++;
// 	j = 0;
// 	while (line[++i] != '\0')
// 	{
// 		stash[j++] = line[i];
// 		line[i] = '\0';
// 	}
// }

// ssize_t	what(int fd, char **line, char *stash)
// {
// 	char	*tmp;
// 	ssize_t	i;

// 	if (!*line)
// 	{
// 		i = make_line(fd, &line, stash);
// 		ft_bzero(stash, BUFF_SIZE);
// 	}
// 	else
// 	{
// 		tmp = *line;
// 		i = make_line(fd, &line, tmp);
// 		free (tmp);
// 	}
// 	return (i);
// }

// char	*get_next_line(int fd)
// {
// 	static char	stash[BUFF_SIZE];
// 	char		*line;
// 	ssize_t		i;

// 	if (!fd)
// 		return (NULL);
// 	line = NULL;
// 	while (!ft_strchr(line, '\n'))
// 	{
// 		i = what(fd, &line, stash);
// 		if (i == -1)
// 			return (NULL);
// 		if (i == 0)
// 			return (line);
// 		if (ft_strchr(line, '\n'))
// 			make_stash(line, stash);
// 	} 
// 	return (line);
// }

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 8; i++)
		printf("%s", get_next_line(fd));
}

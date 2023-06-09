/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:54:14 by ecastong          #+#    #+#             */
/*   Updated: 2023/06/08 16:27:00 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *str, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return ;
	ptr = (char *)str;
	i = 0;
	while (i < len)
		((char *)str)[i++] = 0;
}

char	*ft_strchr(const char *str, int chr)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)chr)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

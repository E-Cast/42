/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:32:42 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/10 20:54:46 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isset(char chr, const char *set);

char	*ft_strtrim(const char *str, const char *set)
{
	size_t	i;
	size_t	sub_start;
	size_t	sub_len;

	if (!str || !set)
		return (NULL);
	i = 0;
	while (st_isset(str[i], set))
		i++;
	sub_start = i;
	while (str[i])
	{
		if (!st_isset(str[i], set))
			sub_len = i - sub_start + 1;
		i++;
	}
	return (ft_substr((char *)str, sub_start, sub_len));
}

static int	st_isset(char chr, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (chr == set[i])
			return (1);
		i++;
	}
	return (0);
}

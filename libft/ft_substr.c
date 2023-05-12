/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:50:17 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/10 21:10:21 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *src, unsigned int start, size_t len)
{
	char	*sub_str;
	char	*str;
	size_t	i;

	if (!src)
		return (NULL);
	str = (char *)src;
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	sub_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_str[i] = str[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

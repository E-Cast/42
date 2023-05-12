/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:12:47 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:21:02 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	dest_len;

	if (!str1 || !str2)
		return (NULL);
	dest_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	dest = (char *)ft_calloc(dest_len, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		dest[i++] = str2[j++];
	dest[i] = '\0';
	return (dest);
}

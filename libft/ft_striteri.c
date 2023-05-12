/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:47:10 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/10 21:43:22 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*fnc)(unsigned int, char*))
{
	size_t	i;

	if (!str || !fnc)
		return ;
	i = 0;
	while (str[i])
	{
		(*fnc)(i, &str[i]);
		i++;
	}
}

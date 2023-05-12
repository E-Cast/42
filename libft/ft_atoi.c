/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:00:42 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/10 22:33:02 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_isspace(int cr);

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		num;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	num = 0;
	while (st_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (ft_isdigit(str[i])))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

static int	st_isspace(int cr)
{
	if ((cr >= 9 && cr <= 13) || cr == ' ')
		return (cr);
	return (0);
}

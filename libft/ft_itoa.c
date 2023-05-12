/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:08:35 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:30:05 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	st_intlen(int num);

char	*ft_itoa(int num)
{
	int				len;
	char			*str;
	unsigned int	tmp;

	len = st_intlen(num);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		tmp = num * -1;
		str[0] = '-';
	}
	else
		tmp = num;
	len--;
	if (tmp == 0)
		str[0] = '0';
	while (tmp > 0)
	{
		str[len] = (tmp % 10) + '0';
		tmp /= 10;
		len--;
	}
	return (str);
}

static int	st_intlen(int num)
{
	int	len;

	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (11);
	len = 0;
	if (num < 0)
	{
		num *= -1;
		len += 1;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

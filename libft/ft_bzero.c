/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:35:13 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/10 22:20:11 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return ;
	ptr = (char *)str;
	i = 0;
	ft_memset(str, 0, len);
}

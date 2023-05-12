/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:49:02 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:16 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *first_node)
{
	size_t	i;

	if (!first_node)
		return (0);
	i = 0;
	while (first_node)
	{
		first_node = first_node -> next;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:46:40 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:30 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *node, void (*fnc)(void *))
{
	if (!node || !fnc)
		return ;
	while (node)
	{
		fnc(node -> content);
		node = node -> next;
	}
}

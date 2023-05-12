/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:37:29 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:42 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **node, void (*del)(void *))
{
	t_list	*next_node;

	if (!*node || !del)
		return ;
	while (*node)
	{
		next_node = (*node)-> next;
		ft_lstdelone(*node, del);
		*node = next_node;
	}
	free(*node);
	*node = NULL;
}

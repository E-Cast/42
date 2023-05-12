/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:12:40 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:59 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **first_node, t_list *new_node)
{
	t_list	*current_node;

	if (!new_node)
		return ;
	if (!*first_node)
		*first_node = new_node;
	else
	{
		current_node = ft_lstlast(*first_node);
		current_node -> next = new_node;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:31:34 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:47 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **first_node, t_list *new_node)
{
	if (!first_node || !new_node)
		return ;
	new_node -> next = *first_node;
	*first_node = new_node;
}

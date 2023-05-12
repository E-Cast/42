/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:56:26 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:29:25 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*fnc)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*new_content;
	t_list	*new_obj;

	if (!list || !fnc || !del)
		return (NULL);
	new_list = NULL;
	while (list)
	{
		new_content = fnc(list -> content);
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		list = list->next;
	}
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:37:46 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/21 21:37:53 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*last;
	t_list	*new;

	root = ft_lstnew((*f)(lst->content));
	last = root;
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&root, *del);
			return (NULL);
		}
		else
			last->next = new;
		last = last->next;
	}
	return (root);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:16:58 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/21 21:17:05 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todel;

	todel = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		ft_lstdelone(todel, del);
		todel = *lst;
	}
}

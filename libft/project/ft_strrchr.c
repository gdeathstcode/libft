/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:18:14 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/16 02:18:15 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	ch;

	save = NULL;
	ch = c;
	while (*s)
	{
		if (*s == ch)
			save = (char *)s;
		s++;
	}
	if (*s == ch)
		save = (char *)s;
	return (save);
}

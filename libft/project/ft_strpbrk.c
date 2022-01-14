/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:17:18 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/19 16:17:19 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	const char	*scanp;
	int			c;
	int			sc;

	while (*s != 0)
	{
		c = *s;
		scanp = charset;
		while (*scanp != 0)
		{
			sc = *scanp;
			if (sc == c)
				return (((char *) s));
			scanp++;
		}
		s++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:35:51 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/18 17:35:52 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	i;
	size_t	j;

	size = len;
	if (ft_strlen(s + start) <= len)
		size = ft_strlen(s + start);
	res = malloc(sizeof(char) * size + 1);
	if (res)
	{
		i = 0;
		j = 0;
		while (s[i])
		{
			if (i >= start && j < size)
				res[j++] = s[i];
			i++;
		}
		res[j] = '\0';
	}
	return (res);
}

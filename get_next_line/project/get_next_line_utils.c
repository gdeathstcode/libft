/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:47:43 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/26 06:48:14 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//size_t	ft_strlen(const char *s)
//{
//	char	*str;
//
//	str = (char *)s;
//	while (*str != '\0')
//		str++;
//	return (str - s);
//}
//
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
//{
//	size_t srcsize;
//	size_t i;
//
//	if (!dst || !src)
//		return (0);
//	srcsize = ft_strlen(src);
//	i = 0;
//	if (dstsize != 0)
//	{
//		while (src[i] != '\0' && i < (dstsize - 1))
//		{
//			dst[i] = src[i];
//			i++;
//		}
//		dst[i] = '\0';
//	}
//	return (srcsize);
//}
//
//char	*ft_strchr(const char *s, int c)
//{
//	char	ch;
//
//	ch = (char)c;
//	while (*s)
//	{
//		if (*s == ch)
//			return ((char *)s);
//		s++;
//	}
//	if (*s == ch)
//		return ((char *)s);
//	return (NULL);
//}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (n == 0 || s1 == s2)
		return (dst);
	while (n--)
		*s1++ = *s2++;
	return (dst);
}

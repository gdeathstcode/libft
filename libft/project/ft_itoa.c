/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 05:46:01 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/21 05:46:01 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	size;

	size = 0;
	if (n == 0 || n < 0)
		size++;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (count_digits(n) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (n / 10 != 0)
	{
		result[i] = ft_abs(n % 10) + '0';
		n = n / 10;
		i++;
	}
	result[i++] = ft_abs(n % 10) + '0';
	if (n < 0)
		result[i++] = '-';
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}

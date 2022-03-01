/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:48:06 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/16 20:48:07 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	int				result;
	int				border;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	border = INT_MAX / 10;
	while (ft_isdigit(*str))
	{
		if ((result > border || (result == border && (*str - '0') > 7))
			&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (*str - '0') > 8))
			&& sign == -1)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

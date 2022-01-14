/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 06:22:28 by gdeathst          #+#    #+#             */
/*   Updated: 2022/01/04 19:36:21 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n / 10 != 0)
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		ft_putchar_fd(ft_abs(n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}

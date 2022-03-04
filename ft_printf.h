/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:31:27 by gdeathst          #+#    #+#             */
/*   Updated: 2022/03/01 08:31:28 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_vfprintf(FILE *stream, const char *format, va_list ap);

void	*ft_itoa(int value, char *buffer, int radix);
void	*ft_utoa(unsigned int value, char *buffer, int radix);
void	*ft_ultoa(unsigned long value, char *buffer, int radix);

#endif
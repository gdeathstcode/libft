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

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_vfprintf(FILE *stream, const char *format, va_list ap);

int	ft_vfprintf_conversion(const char type, va_list ap, int fd);

#endif
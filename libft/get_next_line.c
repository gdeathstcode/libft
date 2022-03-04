/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:47:43 by gdeathst          #+#    #+#             */
/*   Updated: 2022/01/19 18:20:34 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	how_much_to_copy(char *buf, int size)
{
	int		to_copy;
	char	*line_break;

	line_break = (char *)ft_memchr(buf, '\n', size);
	to_copy = size;
	if (line_break != NULL)
		to_copy = line_break - buf + 1;
	return (to_copy);
}

static int	update(char *buf, int size)
{
	int		to_del;

	to_del = how_much_to_copy(buf, size);
	ft_memcpy(buf, buf + to_del, size - to_del);
	size = size - to_del;
	return (size);
}

static char	*generate_new_line(char *line, char *buf, int to_copy)
{
	static int	line_size;
	char		*tmp;

	if (line == NULL)
		line_size = 0;
	tmp = line;
	line = (char *)malloc(sizeof(char) * (line_size + to_copy + 1));
	if (line != NULL)
	{
		ft_memcpy(line, tmp, line_size);
		ft_memcpy(line + line_size, buf, to_copy);
		line[to_copy + line_size] = '\0';
	}
	line_size = to_copy + line_size;
	ft_memdel((void **)&tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	static int	size;
	char		*line;
	int			to_copy;
	char		*break_line;

	if (size == 0)
		size = read(fd, buf, BUFFER_SIZE);
	line = NULL;
	while (size != 0)
	{
		if (size == -1)
			break ;
		break_line = ft_memchr(buf, '\n', size);
		to_copy = how_much_to_copy(buf, size);
		line = generate_new_line(line, buf, to_copy);
		size = update(buf, size);
		if (line == NULL || break_line)
			break ;
		if (size == 0)
			size = read(fd, buf, BUFFER_SIZE);
	}
	if (size == -1)
		ft_memdel((void **)&line);
	return (line);
}

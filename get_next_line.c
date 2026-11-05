/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:48:48 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/05 14:12:40 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t		bytes;
	char		*line;
	static char	*buffer;

	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	buffer[BUFFER_SIZE];
	bytes = read(fd, buffer, BUFFER_SIZE);
	line = get_next_line_reading(buffer);
	return (line);
}

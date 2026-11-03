/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:48:48 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/03 14:34:50 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	size_t	bytes;
	char	*line;
	char	*tmp;
	char	*buffer;

	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	buffer[BUFFER_SIZE];
	bytes = read(fd, buffer, BUFFER_SIZE);
	//fonction line = get_next_line_reading
	return (line);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:48:48 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/04 17:02:10 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_size(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\0')
			return (i);
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}
char	*get_next_line_reading(char *buffer)
{
	int		i;
	char	*stock;
	
	if (!buffer)
		return (NULL);
	i = 0;
	stock = malloc(sizeof(char) * (get_next_line_size(buffer) + 1));
	if (!stock)
		return (NULL);
	while(buffer[i] != '\n' || buffer[i] != '\0')
	{
		stock[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\0')
		stock[i] = '\0';
	if (buffer[i] == '\n')
		stock[i] = '\n';
	return (stock);
}

char	*get_next_line(int fd)
{
	size_t		bytes;
	char		*line;
	static char	*buffer;

	if (!fd || BUFFER_SIZE == 0)
		return (NULL);
	buffer[BUFFER_SIZE];
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		line = get_next_line_reading(buffer);
		return (line);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:48:48 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/06 17:18:40 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buffer;

	bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		bytes = -1;
	while (!gnl_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			stash = gnl_strjoin(stash, buffer);
			if (stash == NULL)
				bytes = -1;
		}
	}
	free(buffer);
	if (bytes < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	gnl_strlcpy(line, stash, (i + 1));
	return (line);
}

static char	*clean_stash(char *stash)
{
	int		i;
	char	*new;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new = malloc(sizeof(char) * (gnl_strlen(stash) - i));
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	gnl_strlcpy(new, (stash + 1 + i), (gnl_strlen(stash) - i));
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}

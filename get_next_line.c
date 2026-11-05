/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:48:48 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/05 18:44:24 by ebayle           ###   ########.fr       */
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
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			stash = ft_strjoin(stash, buffer);
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
	ft_strlcpy(line, stash, (i + 1));
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
	new = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!new)
	{
		free(stash);
		return (NULL);
	}
	ft_strlcpy(new, (stash + 1 + i), (ft_strlen(stash) - i));
	free(stash);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_to_stash(fd, tmp);
	if (tmp == NULL)
		return (NULL);
	line = extract_line(tmp);
	if (line == NULL)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp = clean_stash(tmp);
	return (line);
}

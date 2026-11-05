/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:49:36 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/05 17:47:03 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		o;
	char	*reponse;

	i = 0;
	o = 0;
	if (s2 == 0)
		return (NULL);
	reponse = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!reponse)
	{
		free (s1);
		return (NULL);
	}
	while (s1 && s1[i] != '\0')
	{
		reponse[i] = s1[i];
		i++;
	}
	while (s2[o] != '\0')
		reponse[i++] = s2[o++];
	reponse[i] = '\0';
	free(s1);
	return (reponse);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	len;

	s = (char *)src;
	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (size == 0)
		return (len);
	while (s[i] != '\0' && size - 1 > i)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*occ;

	if (!s)
		return (NULL);
	occ = (char *)s;
	i = 0;
	while (occ[i] != '\0' && occ[i] != (char) c)
		i++;
	if (occ[i] == (char)c)
		return (&occ[i]);
	return (NULL);
}

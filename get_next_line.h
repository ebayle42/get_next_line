/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:49:02 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/03 14:39:11 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*get_next_line_reading(char *buffer, char *stock, size_t nbr);

#endif
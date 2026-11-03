/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_reading.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayle <ebayle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:27:00 by ebayle            #+#    #+#             */
/*   Updated: 2026/11/03 14:42:35 by ebayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_reading(char *buffer, char *stock, size_t nbr)
{
	size_t	i;
	char	*result;

	i = 0;
	while (i <= nbr)
	{
		result = ft_strjoin(buffer, stock);
	}
	return (result);
}
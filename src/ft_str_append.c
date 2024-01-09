/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:04:51 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 12:10:41 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

char	*ft_str_append(char *s1, char *s2)
{
	char	*line;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	line = calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, s1, len_s1);
	ft_memcpy(line + len_s1, s2, len_s2);
	free (s1);
	return (line);
}

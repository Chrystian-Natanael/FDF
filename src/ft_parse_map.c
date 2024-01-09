/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:54 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 12:19:14 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

t_cords	*ft_parse_map(t_data *data, char *fd_map)
{
	int32_t	fd;
	char	*line;
	char	*buffer;

	buffer = NULL;
	data->map_height = 0;
	fd = open(fd_map, O_RDONLY);
	if (fd < 0 || !ft_strnstr(fd_map, ".fdf", ft_strlen(fd_map)))
		ft_error("Invalid map or extension.");
	while (true)
	{
		line = get_next_line(fd);
		if (line)
		{
			buffer = ft_str_append(buffer, line);
			data->map_height++;
		}
		else
			break ;
		free (line);
	}
	close (fd);
	return (0);
}

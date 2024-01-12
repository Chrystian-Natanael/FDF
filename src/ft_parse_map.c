/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:54 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 14:10:15 by cnatanae         ###   ########.fr       */
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
	data->cords->color = 0xFFFFFFFF;
	return (ft_get_cords(data, buffer));
}
t_cords	*ft_get_cords(t_data *data, char *line)
{
	int32_t	size_l;
	int32_t	idx;
	t_cords	*cords;
	char	*line_cpy;

	line_cpy = line;
	size_l = (int32_t)ft_strlen(line);
	cords = calloc(size_l + 1, sizeof(t_cords));
	idx = 0;
	while (idx < size_l)
	{
		while(*line_cpy && ft_isspace(*line_cpy))
			line_cpy++;
		cords[idx].height = ft_atoi(line_cpy);
		while(*line_cpy && !ft_isspace(*line_cpy))
			line_cpy++;
		idx++;
	}
	data->map_width = ft_get_width(line);
	free (line);
	return(cords);
}

int32_t	ft_get_width(char *line)
{
	int32_t	count;

	count = 0;
	while (*line && *line != '\n')
	{
		while (ft_isspace(*line))
			line++;
		if (ft_isdigit(*line) || *line == '-')
			count++;
		while(*line != ' ' && *line)
		{
			if (*line == '\n')
				break ;
			line++;
		}
	}
	return (count);
}

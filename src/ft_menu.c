/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:32 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/16 14:41:52 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render_menu(t_data *data)
{
	mlx_put_string(data->mlx, "888888  88888888ba,    8888888\n", 20, 15);
	mlx_put_string(data->mlx, "88      88      `''8b  88     \n", 20, 30);
	mlx_put_string(data->mlx, "88      88        `8b  88     \n", 20, 45);
	mlx_put_string(data->mlx, "88aaaa  88         88  88aaaa \n", 20, 60);
	mlx_put_string(data->mlx, "88''''  88         88  88'''' \n", 20, 75);
	mlx_put_string(data->mlx, "88      88        `8b  88     \n", 20, 90);
	mlx_put_string(data->mlx, "88      88      .a8P   88     \n", 20, 105);
	mlx_put_string(data->mlx, "88      88888888Y'''   88     \n", 20, 120);
	ft_explain_commands(data);
}

void	ft_explain_commands(t_data *data)
{
	mlx_put_string(data->mlx, "-----------------------------", 20, 160);
	mlx_put_string(data->mlx, "Increase Scale Z == 'J'", 30, 200);
	mlx_put_string(data->mlx, "Decrease Scale Z == 'K'", 30, 240);
	mlx_put_string(data->mlx, "Zoom In == '+'", 30, 280);
	mlx_put_string(data->mlx, "Zoom Out == '-'", 30, 320);
	mlx_put_string(data->mlx, "Move Up == 'W'", 30, 360);
	mlx_put_string(data->mlx, "Move Down == 'S'", 30, 400);
	mlx_put_string(data->mlx, "Move Left == 'A'", 30, 440);
	mlx_put_string(data->mlx, "Move Right == 'D'", 30, 480);
	mlx_put_string(data->mlx, "Rotate Asis+X == 'RIGHT'", 30, 520);
	mlx_put_string(data->mlx, "Rotate Asis-X == 'LEFT'", 30, 560);
	mlx_put_string(data->mlx, "Rotate Asis+Y == 'UP'", 30, 600);
	mlx_put_string(data->mlx, "Rotate Asis-Y == 'DOWN'", 30, 640);
	mlx_put_string(data->mlx, "Rotate Asis-Z == 'Q'", 30, 680);
	mlx_put_string(data->mlx, "Rotate Asis+Z == 'E'", 30, 720);
	mlx_put_string(data->mlx, "Top-Down == '2' || Reset == 'R'", 30, 760);
	mlx_put_string(data->mlx, "Change Color == 'C'", 30, 800);
	mlx_put_string(data->mlx, "Change Type LINE B/X == 'Y'", 30, 840);
	mlx_put_string(data->mlx, "Auto Rotate ON/OFF == '1'", 30, 880);
	mlx_put_string(data->mlx, "For Fun == 'F'", 30, 920);
	mlx_put_string(data->mlx, "CLOSE PROGRAM == 'ESC'", 30, 950);
}

int32_t	ft_count_line(char *line)
{
	int32_t	idx;
	int32_t	count;

	idx = 0;
	count = 0;
	while (line[idx])
	{
		while (ft_isspace(line[idx]) && line[idx])
			idx++;
		if (ft_isdigit(line[idx]) || line[idx] == '-')
			count++;
		while (!ft_isspace(line[idx]) && line[idx])
			idx++;
	}
	return (count);
}

void	ft_validate_map(char *line, int32_t fd, char *buffer)
{
	if (ft_is_retangule(ft_count_line(line)))
	{
		free(line);
		free(buffer);
		close(fd);
		ft_error("Error: map must be a retangule");
	}
}

void	ft_verify_is_null(char *line, int *fd)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		close (*fd);
		ft_error("Error: Invalid Map!");
	}
}

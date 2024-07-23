/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:20:13 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/23 13:09:43 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int32_t	ft_isspace(int32_t c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	ft_ternary(bool condition, int if_true, int if_false)
{
	if (condition)
		return (if_true);
	return (if_false);
}

void	ft_camera_projection(t_data *data)
{
	static int render_menu;

	data->camera.pos.x = 0;
	data->camera.pos.y = -100;
	data->camera.x_rot = -1.100000;
	data->camera.y_rot = -0.650000;
	data->camera.z_rot = 0;
	data->camera.zoom = 40;
	data->camera.height = 50;
	if (!render_menu)
	{
		ft_render_menu(data);
		render_menu = 1;
	}
}

void	ft_camera_panoramic(t_data *data)
{
	data->camera.pos.x = -200;
	data->camera.pos.y = -200;
	data->camera.x_rot = 0.0;
	data->camera.y_rot = 0.0;
	data->camera.z_rot = 0.0;
	data->camera.zoom = 50;
	data->camera.height = 40;
}

void	ft_error(char *msn)
{
	if (errno)
		perror("Error");
	else
		ft_putendl_fd(msn, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:20:13 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 13:43:00 by cnatanae         ###   ########.fr       */
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

void	ft_camera_reset(t_data *data)
{
	data->camera.pos_x = 0;
	data->camera.pos_y = 0;
	data->camera.pos_z = 0;
	data->camera.zoom = 1;
}

void	ft_error(char *msn)
{
	if (errno)
		perror("Error");
	else
		ft_putendl_fd(msn, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

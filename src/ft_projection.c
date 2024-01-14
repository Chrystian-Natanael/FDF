/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:32:19 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 01:08:56 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

t_point	ft_projection(int32_t x, int32_t y, int32_t z, t_data *data)
{
	x *= data->camera.zoom;
	y *= data->camera.zoom;
	z *= (data->camera.zoom * data->camera.height) / 100.0f;
	ft_rotation_x(&y, &z, data->camera.x_rot);
	ft_rotation_y(&x, &z, data->camera.y_rot);
	ft_rotation_z(&x, &y, data->camera.z_rot);
	x += (WIDTH / 2) + data->camera.pos.x;
	y += (HEIGHT / 2) + data->camera.pos.y;
	return (ft_build_point(x, y));
}

void	ft_rotation_x(int32_t *y, int32_t *z, double x)
{
	int32_t	prev_y;
	int32_t	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(x) + prev_z * sin(x);
	*z = -prev_y * sin(x) + prev_z * cos(x);
}

void	ft_rotation_y(int *x, int *z, double y)
{
	int	prev_x;
	int	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(y) + prev_z * sin(y);
	*z = -prev_x * sin(y) + prev_z * cos(y);
}

void	ft_rotation_z(int *x, int *y, double z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z) - prev_y * sin(z);
	*y = prev_x * sin(z) + prev_y * cos(z);
}

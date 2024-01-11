/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:40:10 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/11 11:29:15 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_camera_reset(t_data *data)
{
	data->camera.pos_x = 0;
	data->camera.pos_y = 0;
	data->camera.pos_z = 0;
	data->camera.zoom = 20;
}

void	ft_print_pixel(t_data *data)
{
	ft_bzero(data->image->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	mlx_put_pixel(data->image, data->camera.pos_x, data->camera.pos_y, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x + 1, data->camera.pos_y + 1, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x + 2, data->camera.pos_y + 2, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x + 3, data->camera.pos_y + 3, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x, data->camera.pos_y, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x + 1, data->camera.pos_y + 1, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x + 2, data->camera.pos_y + 2, 0xFFFFFFFF);
	mlx_put_pixel(data->image, data->camera.pos_x + 3, data->camera.pos_y + 3, 0xFFFFFFFF);
}
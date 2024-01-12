/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:40:10 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 10:05:24 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_camera_reset(t_data *data)
{
	data->camera.pos_x = 1000;
	data->camera.pos_y = 500;
	data->camera.pos_z = 0;
	data->camera.zoom = 20;
}

void	ft_print_pixel(t_data *data)
{
	double	idx_a;
	double	idx_b;
	
	ft_bzero(data->image->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	idx_a = data->camera.pos_x;
	while (idx_a < data->camera.pos_x + 10)
	{
		idx_b = data->camera.pos_y;
		while (idx_b < data->camera.pos_y + 10)
		{
			mlx_put_pixel(data->image, idx_a, idx_b, 0xFFFFFFFF);
			idx_b++;
		}
		idx_a++;
	}
}

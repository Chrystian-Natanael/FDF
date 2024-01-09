/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 15:21:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	ft_paint_bucket(mlx_image_t *image, int32_t width, int32_t height, uint32_t color);

void	ft_load_assets(t_data *data)
{
	int32_t	menu_width;

	menu_width = 300;

	data->canva.icon = mlx_load_png("./img/icon.png");
	mlx_set_icon(data->mlx, data->canva.icon);
	data->canva.menu = mlx_new_image(data->mlx, menu_width, HEIGHT);
	mlx_image_to_window(data->mlx, data->canva.menu, 0, 0);
	ft_paint_bucket(data->canva.menu, menu_width, HEIGHT, 0x404040FF);
}

void	ft_paint_bucket(mlx_image_t *image, int32_t width, int32_t height, uint32_t color)
{
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	while (x < width)
	{
		while (y < height)
		{
			mlx_put_pixel(image, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/13 11:28:10 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static void	ft_paint_bucket(mlx_image_t *image, int32_t width, \
int32_t height, uint32_t color);

void	ft_load_assets(t_data *data)
{
	int32_t	menu_width;

	menu_width = 300;
	data->canva.icon = mlx_load_png("./img/icon.png");
	mlx_set_icon(data->mlx, data->canva.icon);
	data->canva.menu = mlx_new_image(data->mlx, menu_width, HEIGHT);
	mlx_image_to_window(data->mlx, data->canva.menu, 0, 0);
	mlx_set_instance_depth(data->canva.menu->instances, 1);
	ft_paint_bucket(data->canva.menu, menu_width, HEIGHT, 0x404040FF);
}

void	ft_paint_bucket(mlx_image_t *image, int32_t width, \
int32_t height, uint32_t color)
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

int32_t	ft_get_z(int32_t x, int32_t y, t_data *data)
{
	return (data->cords[y * data->map_width + x].height);
}

uint32_t	ft_get_color(uint32_t current_color)
{
	if (current_color == WHITE_COLOR)
		return (WHITE);
	else if (current_color == BLUE_COLOR)
		return (BLUE);
	else if (current_color == RED_COLOR)
		return (RED);
	else if (current_color == GREEN_COLOR)
		return (GREEN);
	else if (current_color == PINK_COLOR)
		return (PINK);
	else if (current_color == YELLOW_COLOR)
		return (YELLOW);
	else
		return (WHITE);
}

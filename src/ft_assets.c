/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 15:14:55 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_load_assets(t_data *data)
{
	int32_t	x;
	int32_t	y;
	int32_t	menu_width;

	x = 0;
	y = 0;
	menu_width = 300;

	data->canva.icon = mlx_load_png("./img/icon.png");
	mlx_set_icon(data->mlx, data->canva.icon);
	data->canva.menu = mlx_new_image(data->mlx, menu_width, HEIGHT);
	mlx_image_to_window(data->mlx, data->canva.menu, 0, 0);
	while (x < menu_width)
	{
		while (y < HEIGHT)
		{
			mlx_put_pixel(data->canva.menu, x, y, 0x404040FF);
			y++;
		}
		y = 0;
		x++;
	}
}

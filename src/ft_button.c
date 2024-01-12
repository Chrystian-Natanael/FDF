/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:51:25 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 16:25:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_button(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return ;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		ft_camera_reset(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
		data->camera.zoom += ZOOM_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && data->camera.zoom > 0)
		data->camera.zoom -= ZOOM_SP;
	ft_move(data);
	ft_build_lines(data);
}

void	ft_change_color(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	static uint32_t	current_color = 0;

	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		current_color = (current_color + 1) % NUM_COLORS;
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		current_color -= 1;
	data->cords->color = ft_get_color(current_color);
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

void	ft_move(t_data *data)
{
	if(mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->camera.pos_y -= MV_SP;
	else if(mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->camera.pos_y += MV_SP;
	else if(mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->camera.pos_x -= MV_SP;
	else if(mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->camera.pos_x += MV_SP;
}
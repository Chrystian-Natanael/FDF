/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:22:15 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 03:08:59 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_commands(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		ft_camera_projection(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_J))
		data->camera.height += PROC_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_K))
		data->camera.height -= PROC_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		ft_camera_panoramic(data);
}

void	ft_zoom(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
		data->camera.zoom += ZOOM_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS) && data->camera.zoom > 0)
		data->camera.zoom -= ZOOM_SP;
}

void	ft_rotation_all(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->camera.y_rot += ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->camera.y_rot -= ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->camera.x_rot += ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->camera.x_rot -= ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		data->camera.z_rot += ROT_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		data->camera.z_rot -= ROT_SP;
	if (data->auto_spin == 1)
	{
		data->camera.y_rot -= 0.003;
		data->camera.x_rot += 0.00005;
		data->camera.z_rot -= 0.0005;
	}
}

void	ft_move(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->camera.pos.y -= MV_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->camera.pos.y += MV_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->camera.pos.x -= MV_SP;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->camera.pos.x += MV_SP;
}

void	ft_more_keys(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
	{
		if (data->forfun == 1)
			data->forfun = 0;
		else
			data->forfun = 1;
	}
	if (keydata.key == MLX_KEY_Y && keydata.action == MLX_PRESS)
	{
		if (data->typeline == 1)
			data->typeline = 0;
		else
			data->typeline = 1;
	}
}

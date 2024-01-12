/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:51:25 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 13:52:54 by cnatanae         ###   ########.fr       */
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
		data->camera.zoom += 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
		data->camera.zoom -= 1;
	ft_move(data);
	ft_build_lines(data);
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
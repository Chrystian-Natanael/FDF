/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:58:41 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/13 11:28:23 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_button(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		return ;
	}
	ft_zoom(data);
	ft_rotation_all(data);
	ft_move(data);
	ft_commands(data);
	ft_build_lines(data);
}

int	main(int32_t argc, char **argv)
{
	t_data	data;
	mlx_t	*mlx;

	if (argc == 1 || argc > 2)
	{
		ft_printf("USAGE: ./fdf <map_file.fdf>");
		exit(EXIT_FAILURE);
	}
	data.cords = ft_parse_map(&data, argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (mlx)
	{
		data.mlx = mlx;
		ft_load_assets(&data);
		data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data.mlx, data.image, 0, 0);
		data.cords->color = WHITE;
		ft_camera_projection(&data);
		mlx_loop_hook(data.mlx, ft_button, &data);
		mlx_key_hook(data.mlx, ft_change_color, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
		free(data.cords);
		exit(EXIT_SUCCESS);
	}
	ft_error("Error: Inicialization failure!");
	return (EXIT_FAILURE);
}

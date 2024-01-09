/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:58:41 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 14:32:59 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int32_t argc, char **argv)
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
		data.canva = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		mlx_image_to_window(data.mlx, data.canva, 0, 0);
		mlx_loop_hook(data.mlx, ft_button, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
		free(data.cords);
		exit(EXIT_SUCCESS);
	}
	ft_error("Error: Inicialization failure!");
	return (EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:58:41 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/05 15:45:55 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

typedef struct s_point
{
	int32_t x;
	int32_t y;
	mlx_image_t *background;
	mlx_image_t *black;
	mlx_t *mlx;
	int	posx;
	int	posy;
	int		color;

} t_point;

void	ft_hook(mlx_key_data_t keydata, void* param)
{
	t_point	*point;

	point = param;
	point->x = 0;
	point->y = 0;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(point->mlx);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		while (point->x < WIDTH)
		{
			while (point->y < HEIGHT)
			{
				if (point->color == 0)
					mlx_put_pixel(point->background, point->x, point->y, 0xFF00FFFF);
				else
					mlx_put_pixel(point->background, point->x, point->y, 0xDA1884);
				point->y++;
			}
			point->y = 0;
			point->x++;
		}
		if (point->color == 0)
			point->color = 1;
		else
			point->color = 0;
	}
}

void    print_big_pixel(void *img, int x, int y, uint32_t color)
{
	x *= 10;
	y *= 10;
	for (int i = x; i < x + 10; i++)
		for (int j = y; j < y + 10; j++)
			mlx_put_pixel(img, i, j, color);
}
int    abs(int num)
{
    if (num < 0)
        return (-num);
    return (num);
}

int    ternary(int condition, int if_true, int if_false)
{
    if (condition)
        return (if_true);
    return (if_false);
}
void	desenhar_linha(void *img, int x0, int y0, int x1, int y1, int cor)
{
    int	dx;
    int	dy;
    int	sx;
	int	sy;
	int	error;
	int	e2;

    dx = abs(x1 - x0);
    dy = -abs(y1 - y0);
    sx = ternary(x0 < x1, 1, -1);
    sy = ternary(y0 < y1, 1, -1);
    error = dx + dy;
    while (1)
    {
        print_big_pixel(img, x0, y0, cor);
        if (x0 == x1 && y0 == y1)
            break ;
        e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break ;
            error += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break ;
            error += dx;
            y0 += sy;
        }
    }
}

int	main(int32_t ac, const char **av)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.color = 0;
	point.posx = 10;
	point.posy = 10;
	point.mlx = mlx_init(WIDTH, HEIGHT, "FDF", false);

	if (!point.mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	point.background = mlx_new_image(point.mlx, WIDTH, HEIGHT);
	point.black = mlx_new_image(point.mlx, 10, 10);
	if (!point.background)
	{
		mlx_close_window(point.mlx);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(point.mlx, point.background, 0, 0) == -1)
	{
		mlx_close_window(point.mlx);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(point.mlx, point.black, point.posx, point.posy) == -1)
	{
		mlx_close_window(point.mlx);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (point.x < WIDTH)
	{
		while (point.y < HEIGHT)
		{
			mlx_put_pixel(point.background, point.x, point.y, 0xFFFFFFFF);
			point.y++;
		}
		point.y = 0;
		point.x++;
	}
	desenhar_linha(point.black, 0, 0, 15, 0, 0xFFAF00FF);
	mlx_put_string(point.mlx, "RTFM!", 10, 10);
	mlx_key_hook(point.mlx, ft_hook, &point);
	mlx_loop(point.mlx);
	mlx_terminate(point.mlx);
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:16:01 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/13 08:44:41 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_build_lines(t_data *data)
{
	int32_t	x;
	int32_t	y;

	ft_bzero(data->image->pixels, WIDTH * HEIGHT * sizeof(int32_t));
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_draw_line(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_line(t_data *data, int32_t x, int32_t y)
{
	if (x != data->map_width -1)
		ft_plot_line(data, ft_projection(x, y, ft_get_z(x, y, data), data), \
		ft_projection(x + 1, y, ft_get_z(x + 1, y, data), data));
	if (y != data->map_height -1)
		ft_plot_line(data, ft_projection(x, y, ft_get_z(x, y, data), data), \
		ft_projection(x, y + 1, ft_get_z(x, y + 1, data), data));
}

void	ft_plot_line(t_data *data, t_point start, t_point end)
{
	t_point	delta;
	t_point	incr;
	t_point	cur;
	int32_t	error;

	delta.x = abs(start.x - end.x);
	delta.y = abs(start.y - end.y);
	incr.x = ft_ternary(end.x < start.x, 1, -1);
	incr.y = ft_ternary(end.y < start.y, 1, -1);
	error = 2 * (delta.y - delta.x);
	cur = end;
	while (true)
	{
		if (data->image && cur.x > 0 && cur.y > 0)
		{
			if ((cur.x < (int32_t)data->image->width) && (cur.y > 0 && \
			cur.y < (int32_t)data->image->height))
				mlx_put_pixel(data->image, cur.x, cur.y, data->cords->color);
		}
		if (cur.x == start.x && cur.y == start.y)
			break ;
		if (error >= 0)
		{
			cur.y += incr.y;
			error -= 2 * delta.x;
		}
		if (error < 0)
		{
			cur.x += incr.x;
			error += 2 * delta.y;
		}
	}
}

t_point	ft_projection(int32_t x, int32_t y, int32_t z, t_data *data)
{
	x *= data->camera.zoom;
	y *= data->camera.zoom;
	z *= (data->camera.zoom * data->camera.height) / 100.0f;
	x += (WIDTH / 2) + data->camera.pos_x;
	y += (HEIGHT / 2) + data->camera.pos_y;
	ft_isometric(&x, &y, z);
	return (ft_build_point(x, y));
}

void	ft_isometric(int32_t *x, int32_t *y, int32_t z)
{
	int32_t	prev_x;
	int32_t	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5235988);
	*y = -z + (prev_x + prev_y) * sin(0.5235988);
}

t_point	ft_build_point(int32_t x, int32_t y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

int32_t	ft_get_z(int32_t x, int32_t y, t_data *data)
{
	return (data->cords[y * data->map_width + x].height);
}
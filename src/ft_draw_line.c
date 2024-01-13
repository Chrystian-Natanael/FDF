/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:16:01 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/13 11:18:51 by cnatanae         ###   ########.fr       */
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
	t_bresen	vars;

	ft_settings_vars(&vars, &start, &end);
	while (true)
	{
		if (data->image && vars.cur->x > 0 && vars.cur->y > 0)
		{
			if ((vars.cur->x < (int32_t)data->image->width) && \
			(vars.cur->y > 0 && vars.cur->y < (int32_t)data->image->height))
				mlx_put_pixel(data->image, vars.cur->x, vars.cur->y, \
				data->cords->color);
		}
		if (vars.cur->x == start.x && vars.cur->y == start.y)
			break ;
		if (vars.error >= 0)
		{
			vars.cur->y += vars.incr.y;
			vars.error -= 2 * vars.delta.x;
		}
		if (vars.error < 0)
		{
			vars.cur->x += vars.incr.x;
			vars.error += 2 * vars.delta.y;
		}
	}
}

void	ft_settings_vars(t_bresen *vars, t_point *start, \
t_point *end)
{
	vars->delta.x = abs(start->x - end->x);
	vars->delta.y = abs(start->y - end->y);
	vars->incr.x = ft_ternary(end->x < start->x, 1, -1);
	vars->incr.y = ft_ternary(end->y < start->y, 1, -1);
	vars->error = 2 * (vars->delta.y - vars->delta.x);
	vars->cur = end;
}

t_point	ft_build_point(int32_t x, int32_t y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

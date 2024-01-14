/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:02:41 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 02:23:11 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

float	absolute(float x )
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	put_valid_pixel(t_data *data, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

uint32_t	set_brightness(uint32_t color, float brightness)
{
	int	brightness_rgba;

	brightness_rgba = brightness * 255;
	return ((color & 0xFFFFFF00) | brightness_rgba);
}

void	ft_set_vars_p1(t_xiao *vars, t_point start, t_point end, t_data *data)
{
	vars->x1 = start.x;
	vars->x2 = end.x;
	vars->y1 = start.y;
	vars->y2 = end.y;
	vars->color = data->cords->color;
	vars->dx = (double)vars->x2 - (double)vars->x1;
	vars->dy = (double)vars->y2 - (double)vars->y1;
}

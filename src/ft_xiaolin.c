/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:24:46 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 01:39:31 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))
#define swap_(a, b) do{ __typeof__(a) tmp;	tmp = a; a = b; b = tmp; }while(0)

float absolute(float x )
{
	if (x < 0) return -x;
	else return x;
}

void	put_valid_pixel(t_data *data, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

uint32_t set_brightness(uint32_t color, float brightness)
{
	int	brightness_rgba;
	brightness_rgba = brightness * 255;
	return ((color & 0xFFFFFF00) | brightness_rgba);
}

void	ft_plot_line_xin(t_data *data, t_point start, t_point end)
{
	t_xiao	vars;
	
	ft_set_vars_p1(&vars, start, end, data);
	if (absolute(vars.dx) > absolute(vars.dy))
	{
		if ( vars.x2 < vars.x1 )
		{
			swap_(vars.x1, vars.x2);
			swap_(vars.y1, vars.y2);
		}
		ft_set_vars_p2(&vars, data);
		int x;
		for(x=vars.xpxl1+1; x < vars.xpxl2; x++)
		{
			put_valid_pixel(data, x, ipart_(vars.intery), set_brightness(vars.color, rfpart_(vars.intery)));
			put_valid_pixel(data, x, ipart_(vars.intery) + 1, set_brightness(vars.color, fpart_(vars.intery)));
			vars.intery += vars.gradient;
		}
	}
	else
	{
		if ( vars.y2 < vars.y1 ) {
			swap_(vars.x1, vars.x2);
			swap_(vars.y1, vars.y2);
		}
		ft_set_vars_p3(&vars, data);
		int y;
		for(y=vars.ypxl1+1; y < vars.ypxl2; y++) {
			put_valid_pixel(data, ipart_(vars.interx), y, set_brightness(vars.color, rfpart_(vars.interx)));
			put_valid_pixel(data, ipart_(vars.interx) + 1, y, set_brightness(vars.color, fpart_(vars.interx)));
			vars.interx += vars.gradient;
		}
	}
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

void	ft_set_vars_p2(t_xiao *vars, t_data *data)
{
	vars->gradient = vars->dy / vars->dx;
	vars->xend = round_(vars->x1);
	vars->yend = vars->y1 + vars->gradient*(vars->xend - vars->x1);
	vars->xgap = rfpart_(vars->x1 + 0.5);
	vars->xpxl1 = vars->xend;
	vars->ypxl1 = ipart_(vars->yend);
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1, set_brightness\
	(vars->color, rfpart_(vars->yend)* vars->xgap));
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1+1, set_brightness\
	(vars->color, fpart_(vars->yend)* vars->xgap));
	vars->intery = vars->yend + vars->gradient;
	vars->xend = round_(vars->x2);
	vars->yend = vars->y2 + vars->gradient*(vars->xend - vars->x2);
	vars->xgap = fpart_(vars->x2+0.5);
	vars->xpxl2 = vars->xend;
	vars->ypxl2 = ipart_(vars->yend);
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2, set_brightness\
	(vars->color, rfpart_(vars->yend) * vars->xgap));
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2 + 1, set_brightness\
	(vars->color, fpart_(vars->yend) * vars->xgap));
}

void	ft_set_vars_p3(t_xiao *vars, t_data *data)
{
	vars->gradient = vars->dx / vars->dy;
	vars->yend = round_(vars->y1);
	vars->xend = vars->x1 + vars->gradient*(vars->yend - vars->y1);
	vars->ygap = rfpart_(vars->y1 + 0.5);
	vars->ypxl1 = vars->yend;
	vars->xpxl1 = ipart_(vars->xend);
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1, set_brightness\
	(vars->color, rfpart_(vars->xend) * vars->ygap));
	put_valid_pixel(data, vars->xpxl1 + 1, vars->ypxl1, set_brightness\
	(vars->color, fpart_(vars->xend) * vars->ygap));
	vars->interx = vars->xend + vars->gradient;
	vars->yend = round_(vars->y2);
	vars->xend = vars->x2 + vars->gradient*(vars->yend - vars->y2);
	vars->ygap = fpart_(vars->y2+0.5);
	vars->ypxl2 = vars->yend;
	vars->xpxl2 = ipart_(vars->xend);
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2, set_brightness\
	(vars->color, rfpart_(vars->xend) * vars->ygap));
	put_valid_pixel(data, vars->xpxl2 + 1, vars->ypxl2, set_brightness\
	(vars->color, fpart_(vars->xend) * vars->ygap));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:24:46 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/13 22:53:20 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

#define swap_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)
#define round_(X) ((int)(((double)(X))+0.5))
#define rfpart_(X) (1.0-fpart_(X))
#define ipart_(X) ((int)(X))
#define fpart_(X) (((double)(X))-(double)ipart_(X))

void	ft_plot_line_xin(t_data *data, t_point start, t_point end)
{
	t_xiao	vars;

	ft_settings_vars_xiao(data, &vars, &start, &end);
}
void	ft_settings_vars_xiao( t_data *data, t_xiao *vars, t_point *start, \
t_point *end)
{
	int32_t	x;
	int32_t	y;

	vars->delta.x = abs(start->x - end->x);
	vars->delta.y = abs(start->y - end->y);
	if ( abs(vars->delta.x) > abs(vars->delta.y) )
	{
		if (end->x < start->x)
		{
			swap_(start->x, end->x);
			swap_(start->y, end->y);
		}
	}
	vars->gradient = vars->delta.y / vars->delta.x;
	vars->xend = round_(start->x);
	vars->yend = start->y + vars->gradient * (vars->xend - start->x);
	vars->xgap = rfpart_(start->x + 0.5);
	vars->xpxl1 = vars->xend;
	vars->ypxl1 = ipart_(vars->yend);
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1, set_brightness(0xFFFFFFFF, rfpart_(vars->yend) * vars->xgap));
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1 + 1, set_brightness(0xFFFFFFFF, fpart_(vars->yend) * vars->xgap));
	vars->intery = vars->yend + vars->gradient;
	vars->xend = round_(end->x);
	vars->yend = end->y + vars->gradient * (vars->xend - end->x);
	vars->xgap = fpart_(end->x + 0.5);
	vars->xpxl2 = vars->xend;
	vars->ypxl2 = ipart_(vars->yend);
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2, set_brightness(0xFFFFFFFF, rfpart_(vars->yend) * vars->xgap));
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2 + 1, set_brightness(0xFFFFFFFF, fpart_(vars->yend) * vars->xgap));
	x = vars->xpxl1 + 1;
	while (x < vars->xpxl2)
	{
		put_valid_pixel(data, x, ipart_(vars->intery), set_brightness(0xFFFFFFFF, rfpart_(vars->intery)));
		put_valid_pixel(data, x, ipart_(vars->intery) + 1, set_brightness(0xFFFFFFFF, fpart_(vars->intery)));
		vars->intery += vars->gradient;
		x++;
	}
	if (end->y < start->y)
	{
		swap_(start->x, end->x);
		swap_(start->y, end->y);
	}
	vars->gradient = vars->delta.x / vars->delta.y;
	vars->yend = round_(start->y);
	vars->xend = start->x + vars->gradient * (vars->yend - start->y);
	vars->ygap = rfpart_(start->y + 0.5);
	vars->ypxl1 = vars->yend;
	vars->xpxl1 = ipart_(vars->xend);
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1, set_brightness(0xFFFFFFFF, rfpart_(vars->xend) * vars->ygap));
	put_valid_pixel(data, vars->xpxl1 + 1, vars->ypxl1, set_brightness(0xFFFFFFFF, fpart_(vars->xend)* vars->ygap));
	vars->interx = vars->xend + vars->gradient;
	vars->yend = round_(end->y);
	vars->xend = end->x + vars->gradient * (vars->yend - end->y);
	vars->ygap = fpart_(end->y + 0.5);
	vars->ypxl2 = vars->yend;
	vars->xpxl2 = ipart_(vars->xend);
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2, set_brightness(0xFFFFFFFF, rfpart_(vars->xend) * vars->ygap));
	put_valid_pixel(data, vars->xpxl2 + 1, vars->ypxl2, set_brightness(0xFFFFFFFF, fpart_(vars->xend) * vars->ygap));
	y = vars->ypxl1 + 1;
	while (y < vars->ypxl2)
	{
		put_valid_pixel(data, ipart_(vars->interx), y, set_brightness(0xFFFFFFFF, rfpart_(vars->interx)));
		put_valid_pixel(data, ipart_(vars->interx) + 1, y, set_brightness(0xFFFFFFFF, fpart_(vars->interx)));
		vars->interx += vars->gradient;
		y++;
	}
}

uint32_t	set_brightness(uint32_t color, float brightness)
{
	int	brightness_rgba;

	brightness_rgba = brightness * 255;
	return (color | brightness_rgba);
}

void	put_valid_pixel(t_data *data, int x, int y, uint32_t color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(data->image, x, y, color);
}

#undef swap_
#undef ipart_
#undef fpart_
#undef round_

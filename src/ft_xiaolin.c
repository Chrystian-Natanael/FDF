/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:24:46 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 00:27:36 by cnatanae         ###   ########.fr       */
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
	return (color | brightness_rgba);
}

void	ft_plot_line_xin(t_data *data, t_point start, t_point end)
{
	int		x1 = start.x;
	int		x2 = end.x;
	int		y1 = start.y;
	int		y2 = end.y;
////////////////////////////////////////////////////////////////
	int32_t	color = data->cords->color;		// COLOCAR A COR AQUI
////////////////////////////////////////////////////////////////

	double dx = (double)x2 - (double)x1;
	double dy = (double)y2 - (double)y1;
	if ( absolute(dx) > absolute(dy) ) {
		if ( x2 < x1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dy / dx;
		double xend = round_(x1);
		double yend = y1 + gradient*(xend - x1);
		double xgap = rfpart_(x1 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);
		put_valid_pixel(data, xpxl1, ypxl1, set_brightness(color, rfpart_(yend)*xgap));
		put_valid_pixel(data, xpxl1, ypxl1+1, set_brightness(color, fpart_(yend)*xgap));
		double intery = yend + gradient;

		xend = round_(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = fpart_(x2+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		put_valid_pixel(data, xpxl2, ypxl2, set_brightness(color, rfpart_(yend) * xgap));
		put_valid_pixel(data, xpxl2, ypxl2 + 1, set_brightness(color, fpart_(yend) * xgap));

		int x;
		for(x=xpxl1+1; x < xpxl2; x++) {
			put_valid_pixel(data, x, ipart_(intery), set_brightness(color, rfpart_(intery)));
			put_valid_pixel(data, x, ipart_(intery) + 1, set_brightness(color, fpart_(intery)));
			intery += gradient;
		}
	} else {
		if ( y2 < y1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dx / dy;
		double yend = round_(y1);
		double xend = x1 + gradient*(yend - y1);
		double ygap = rfpart_(y1 + 0.5);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);
		put_valid_pixel(data, xpxl1, ypxl1, set_brightness(color, rfpart_(xend)*ygap));
		put_valid_pixel(data, xpxl1 + 1, ypxl1, set_brightness(color, fpart_(xend)*ygap));
		double interx = xend + gradient;

		yend = round_(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = fpart_(y2+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		put_valid_pixel(data, xpxl2, ypxl2, set_brightness(color, rfpart_(xend) * ygap));
		put_valid_pixel(data, xpxl2 + 1, ypxl2, set_brightness(color, fpart_(xend) * ygap));

		int y;
		for(y=ypxl1+1; y < ypxl2; y++) {
			put_valid_pixel(data, ipart_(interx), y, set_brightness(color, rfpart_(interx)));
			put_valid_pixel(data, ipart_(interx) + 1, y, set_brightness(color, fpart_(interx)));
			interx += gradient;
		}
	}
}

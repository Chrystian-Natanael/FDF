/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:24:46 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 02:32:06 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_plot_line_xin(t_data *data, t_point start, t_point end)
{
	t_xiao	vars;

	ft_set_vars_p1(&vars, start, end, data);
	if (absolute(vars.dx) > absolute(vars.dy))
		ft_process_p1(data, &vars);
	else
		ft_process_p2(data, &vars);
}

void	ft_process_p1(t_data *data, t_xiao *vars)
{
	int32_t	x;

	if (vars->x2 < vars->x1)
	{
		swap(&vars->x1, &vars->x2);
		swap(&vars->y1, &vars->y2);
	}
	ft_set_vars_p2(vars, data);
	x = vars->xpxl1 + 1;
	while (x < vars->xpxl2)
	{
		put_valid_pixel(data, x, ipart_(vars->intery), \
		set_brightness(vars->color, rfpart_(vars->intery)));
		put_valid_pixel(data, x, ipart_(vars->intery) + 1, \
		set_brightness (vars->color, fpart_(vars->intery)));
		vars->intery += vars->gradient;
		x++;
	}
}

void	ft_process_p2(t_data *data, t_xiao *vars)
{
	int32_t	y;

	if (vars->y2 < vars->y1)
	{
		swap(&vars->x1, &vars->x2);
		swap(&vars->y1, &vars->y2);
	}
	ft_set_vars_p3(vars, data);
	y = vars->ypxl1 + 1;
	while (y < vars->ypxl2)
	{
		put_valid_pixel(data, ipart_(vars->interx), y, \
		set_brightness(vars->color, rfpart_(vars->interx)));
		put_valid_pixel(data, ipart_(vars->interx) + 1, y, \
		set_brightness(vars->color, fpart_(vars->interx)));
		vars->interx += vars->gradient;
		y++;
	}
}

void	ft_set_vars_p2(t_xiao *vars, t_data *data)
{
	vars->gradient = vars->dy / vars->dx;
	vars->xend = round_(vars->x1);
	vars->yend = vars->y1 + vars->gradient * (vars->xend - vars->x1);
	vars->xgap = rfpart_(vars->x1 + 0.5);
	vars->xpxl1 = vars->xend;
	vars->ypxl1 = ipart_(vars->yend);
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1, \
	set_brightness(vars->color, rfpart_(vars->yend) * vars->xgap));
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1 + 1, \
	set_brightness(vars->color, fpart_(vars->yend) * vars->xgap));
	vars->intery = vars->yend + vars->gradient;
	vars->xend = round_(vars->x2);
	vars->yend = vars->y2 + vars->gradient * (vars->xend - vars->x2);
	vars->xgap = fpart_(vars->x2 + 0.5);
	vars->xpxl2 = vars->xend;
	vars->ypxl2 = ipart_(vars->yend);
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2, \
	set_brightness(vars->color, rfpart_(vars->yend) * vars->xgap));
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2 + 1, \
	set_brightness(vars->color, fpart_(vars->yend) * vars->xgap));
}

void	ft_set_vars_p3(t_xiao *vars, t_data *data)
{
	vars->gradient = vars->dx / vars->dy;
	vars->yend = round_(vars->y1);
	vars->xend = vars->x1 + vars->gradient * (vars->yend - vars->y1);
	vars->ygap = rfpart_(vars->y1 + 0.5);
	vars->ypxl1 = vars->yend;
	vars->xpxl1 = ipart_(vars->xend);
	put_valid_pixel(data, vars->xpxl1, vars->ypxl1, \
	set_brightness(vars->color, rfpart_(vars->xend) * vars->ygap));
	put_valid_pixel(data, vars->xpxl1 + 1, vars->ypxl1, \
	set_brightness(vars->color, fpart_(vars->xend) * vars->ygap));
	vars->interx = vars->xend + vars->gradient;
	vars->yend = round_(vars->y2);
	vars->xend = vars->x2 + vars->gradient * (vars->yend - vars->y2);
	vars->ygap = fpart_(vars->y2 + 0.5);
	vars->ypxl2 = vars->yend;
	vars->xpxl2 = ipart_(vars->xend);
	put_valid_pixel(data, vars->xpxl2, vars->ypxl2, \
	set_brightness(vars->color, rfpart_(vars->xend) * vars->ygap));
	put_valid_pixel(data, vars->xpxl2 + 1, vars->ypxl2, \
	set_brightness(vars->color, fpart_(vars->xend) * vars->ygap));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:47:18 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/14 09:50:15 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_is_ff_p1(t_data *data, int32_t x, int32_t y)
{
	if (data->forfun == 0)
	{
		if (data->typeline == 1)
			ft_plot_line(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x + 1, y, ft_get_z(x + 1, y, data), data));
		else
			ft_plot_line_xin(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x + 1, y, ft_get_z(x + 1, y, data), data));
	}
	else if (((ft_get_z(x,y, data) > 0)
		|| (ft_get_z(x + 1,y, data) > 0)) && data->forfun == 1)
	{
		if (data->typeline == 1)
			ft_plot_line(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x + 1, y, ft_get_z(x + 1, y, data), data));
		else
			ft_plot_line_xin(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x + 1, y, ft_get_z(x + 1, y, data), data));
	}
}

void	ft_is_ff_p2(t_data *data, int32_t x, int32_t y)
{
	if (data->forfun == 0)
	{
		if (data->typeline == 1)
			ft_plot_line(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x, y + 1, ft_get_z(x, y + 1, data), data));
		else
			ft_plot_line_xin(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x, y + 1, ft_get_z(x, y + 1, data), data));
	}
	else if (((ft_get_z(x,y, data) > 0)
	|| (ft_get_z(x,y + 1, data) > 0)) && data->forfun == 1)
	{
		if (data->typeline == 1)
			ft_plot_line(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x, y + 1, ft_get_z(x, y + 1, data), data));
		else
			ft_plot_line_xin(data, ft_projection(x, y, ft_get_z(x, y, data), \
			data), ft_projection(x, y + 1, ft_get_z(x, y + 1, data), data));
	}
}

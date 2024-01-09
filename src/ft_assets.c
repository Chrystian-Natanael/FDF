/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:14:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 15:04:06 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_load_assets(t_data *data)
{
	data->canva.icon = mlx_load_png("./img/icon.png");
	mlx_set_icon(data->mlx, data->canva.icon);
}
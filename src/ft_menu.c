/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:52:32 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/13 19:17:25 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render_menu(t_data *data)
{
	mlx_put_string(data->mlx, "888888  88888888ba,    8888888\n", 20, 15);
	mlx_put_string(data->mlx, "88      88      `''8b  88     \n", 20, 30);
	mlx_put_string(data->mlx, "88      88        `8b  88     \n", 20, 45);
	mlx_put_string(data->mlx, "88aaaa  88         88  88aaaa \n", 20, 60);
	mlx_put_string(data->mlx, "88''''  88         88  88'''' \n", 20, 75);
	mlx_put_string(data->mlx, "88      88        `8b  88     \n", 20, 90);
	mlx_put_string(data->mlx, "88      88      .a8P   88     \n", 20, 105);
	mlx_put_string(data->mlx, "88      88888888Y'''   88     \n", 20, 120);	
	ft_explain_commands(data);
}

void	ft_explain_commands(t_data *data)
{
	mlx_put_string(data->mlx, "-----------------------------", 20, 160);
	mlx_put_string(data->mlx, "Increase Scale Z == 'J'", 40, 200);
	mlx_put_string(data->mlx, "Decrease Scale Z == 'K'", 40, 240);
	mlx_put_string(data->mlx, "Zoom In == '+'", 40, 280);
	mlx_put_string(data->mlx, "Zoom Out == '-'", 40, 320);
	mlx_put_string(data->mlx, "Move Up == 'W'", 40, 360);
	mlx_put_string(data->mlx, "Move Down == 'S'", 40, 400);
	mlx_put_string(data->mlx, "Move Left == 'A'", 40, 440);
	mlx_put_string(data->mlx, "Move Right == 'D'", 40, 480);
	mlx_put_string(data->mlx, "Rotate Asis+X == 'RIGHT'", 40, 520);
	mlx_put_string(data->mlx, "Rotate Asis-X == 'LEFT'", 40, 560);
	mlx_put_string(data->mlx, "Rotate Asis+Y == 'UP'", 40, 600);
	mlx_put_string(data->mlx, "Rotate Asis-Y == 'DOWN'", 40, 640);
	mlx_put_string(data->mlx, "Rotate Asis-Z == 'Q'", 40, 680);
	mlx_put_string(data->mlx, "Rotate Asis+Z == 'E'", 40, 720);
	mlx_put_string(data->mlx, "Perspective == '2 - 4'", 40, 760);
	mlx_put_string(data->mlx, "Change Color + == 'C'", 40, 800);
	mlx_put_string(data->mlx, "Change Color - == 'V'", 40, 840);
	mlx_put_string(data->mlx, "Auto Rotate ON/OFF == '1'", 40, 880);
	mlx_put_string(data->mlx, "For Fun == 'F'", 40, 920);
	mlx_put_string(data->mlx, "CLOSE PROGRAM == 'ESC'", 40, 950);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:58:53 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 10:04:07 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "MLX42/MLX42.h"

# define WIDTH 1900
# define HEIGHT 1080
# define MV_SP 5

typedef struct	s_cords
{
	int32_t	color;
	int32_t	height;
}			t_cords;

typedef struct	s_canva
{
	mlx_texture_t	*icon;
	mlx_image_t		*menu;
}					t_canva;

typedef struct	s_cam
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	int32_t	zoom;
}			t_cam;

typedef struct	s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int32_t		map_height;
	int32_t		map_width;
	t_cords		*cords;
	t_canva		canva;
	t_cam		camera;
}				t_data;

int		ft_ternary(int condition, int if_true, int if_false);
char	*ft_str_append(char *s1, char *s2);
void	ft_print_pixel(t_data *data);
void	ft_error(char *msn);
void	ft_button(void *param);
void	ft_load_assets(t_data *data);
void	ft_camera_reset(t_data *data);
void	ft_move(t_data *data);
int32_t	ft_isspace(int32_t c);
t_cords	*ft_parse_map(t_data *data, char *fd_map);

#endif
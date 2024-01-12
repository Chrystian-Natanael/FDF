/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:58:53 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/12 16:24:15 by cnatanae         ###   ########.fr       */
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
# define ZOOM_SP 1

# define WHITE 0xFFFFFFFF
# define BLUE 0x0000FFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define PINK 0xFFFF00FF
# define YELLOW 0xFF00FFFF

typedef struct	s_cords
{
	uint32_t	color;
	int32_t		height;
}				t_cords;

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

typedef struct s_point
{
	int32_t	x;
	int32_t	y;
}			t_point;

typedef enum e_typeline
{
	XIAOLIN =	1,
	BRESENHAN =	2
}				t_typeline;

typedef enum e_colors
{
	WHITE_COLOR = 0,
	BLUE_COLOR = 1,
	RED_COLOR = 2,
	GREEN_COLOR = 3,
	PINK_COLOR = 4,
	YELLOW_COLOR = 5,
	NUM_COLORS = 6
}	t_colors;

int			ft_ternary(bool condition, int if_true, int if_false);
char		*ft_str_append(char *s1, char *s2);
void		ft_error(char *msn);
void		ft_button(void* param);
void		ft_load_assets(t_data *data);
void		ft_camera_reset(t_data *data);
void		ft_move(t_data *data);
void		ft_draw_line(t_data *data, int32_t x, int32_t y);
int32_t		ft_isspace(int32_t c);
int32_t		ft_get_width(char *line);
t_cords		*ft_parse_map(t_data *data, char *fd_map);
t_cords		*ft_get_cords(t_data *data, char *line);
void		ft_change_color(mlx_key_data_t keydata, void *param);


void		ft_build_lines(t_data *data);
void		ft_draw_line(t_data *data, int32_t x, int32_t y);
void		ft_plot_line(t_data *data, t_point start, t_point end);
t_point		ft_projection(int32_t x, int32_t y, t_data *data);
t_point		ft_build_point(int32_t x, int32_t y);
uint32_t	ft_get_color(uint32_t current_color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 05:58:53 by cnatanae          #+#    #+#             */
/*   Updated: 2024/01/09 14:34:39 by cnatanae         ###   ########.fr       */
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

typedef struct s_cords
{
	int32_t	color;
	int32_t	height;
}			t_cords;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*canva;
	int32_t			map_height;
	int32_t			map_width;
	t_cords			*cords;
	mlx_texture_t	*icon;
}					t_data;


void	ft_error(char *msn);
void	ft_button(void *param);
char	*ft_str_append(char *s1, char *s2);
t_cords	*ft_parse_map(t_data *data, char *fd_map);
void	ft_load_assets(t_data *data);


#endif
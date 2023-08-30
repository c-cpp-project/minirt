/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utility.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:00:48 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/30 21:41:18 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILITY_H
# define MLX_UTILITY_H
# define TRUE 1
# define FALSE 0
# define RED 0
# define GREEN 1
# define BLUE 2
# define X 0
# define Y 1
# define Z 2

# include"../structure.h"
# include"../parsing/__init__.h"
# include "../utils/utils.h"
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<math.h>
# include <mlx.h>

typedef struct s_img_ptr
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img_ptr;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_ptr	wins;
}	t_mlx;

// mlx_color.c
int		create_trgb(int t, int r, int g, int b);
void	mlx_set_window(t_mlx *mlx_vars, t_image *img);
void	my_mlx_pixel_put(t_img_ptr *data, int x, int y, t_color rgb);
int		key_code_press(int keycode, t_mlx *vars);

// mlx_color.c
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

// mlx_draw.c
t_color	ray2color(t_ray_info ray_info, t_data data, double u, double v);
void	ft_draw(t_ray_info ray_info, t_data data, t_mlx mlx_vars);
#endif
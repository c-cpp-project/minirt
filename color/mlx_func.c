/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:06:10 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 14:06:26 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx_utility.h"

void	my_mlx_pixel_put(t_img_ptr *data, int x, int y, t_color rgb)
{
	char	*dst;
	int		color;

	color = create_trgb(0, (int)(rgb.r * 255.999), (int)(rgb.g * 255.999), \
	(int)(rgb.b * 255.999));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_set_window(t_mlx *mlx_vars, t_image *img)
{
	mlx_vars->mlx_ptr = mlx_init();
	mlx_vars->win_ptr = mlx_new_window(mlx_vars->mlx_ptr, img->image_width, \
	img->image_height, "MINIRT");
	mlx_vars->wins.img = mlx_new_image(mlx_vars->mlx_ptr, img->image_width, \
	img->image_height);
	mlx_vars->wins.addr = mlx_get_data_addr(mlx_vars->wins.img, \
	&(mlx_vars->wins.bits_per_pixel), &(mlx_vars->wins.line_length), \
	&(mlx_vars->wins.endian));
}

int	key_code_press(int keycode, t_mlx *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return (0);
}

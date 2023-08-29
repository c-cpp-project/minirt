/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:04:48 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/29 18:45:20 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx_utility.h"

// gcc -lmlx -framework OpenGl -framework AppKit
void	my_mlx_pixel_put(t_img_ptr *data, int x, int y, t_color rgb)
{
	char	*dst;
	int		color;

	color = create_trgb(0, rgb.r, rgb.g, rgb.b);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_set_window(void **mlx_ptr, void **win_ptr, t_img_ptr *wins, \
t_image *img)
{
	(*mlx_ptr) = mlx_init();
	(*win_ptr) = mlx_new_window((*mlx_ptr), img->image_width, \
	img->image_height, "MINIRT");
	wins->img = mlx_new_image((*mlx_ptr), img->image_width, \
	img->image_height);
	wins->addr = mlx_get_data_addr(wins->img, &(wins->bits_per_pixel), \
	&(wins->line_length), &(wins->endian));
}

int main()
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_ptr	wins;
	t_color		rgb;
	t_image		img;

	// set in main
	mlx_set_window(&mlx_ptr, &win_ptr, &wins, &img);

	// draw each point
	rgb.b = 0;
	rgb.g = 0;
	rgb.r = 255;
	for (int i = 0 ; i < img.image_width ; i++)
	{
		for (int j = 0 ; j < img.image_height; j++)
		{
			my_mlx_pixel_put(&wins, i, j, rgb);
		}	
	}

	// set in main
	mlx_put_image_to_window(mlx_ptr, win_ptr, wins.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
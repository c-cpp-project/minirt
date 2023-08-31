#include"mlx_utility.h"

// gcc -lmlx -framework OpenGl -framework AppKit
void	my_mlx_pixel_put(t_img_ptr *data, int x, int y, t_color rgb)
{
	char	*dst;
	int		color;

	color = create_trgb(0, (int)(rgb.r * 255.999), (int)(rgb.g * 255.999), (int)(rgb.b * 255.999));
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

// int main()
// {
// 	void		*mlx_ptr;
// 	void		*win_ptr;
// 	t_img_ptr	wins;
// 	t_color		rgb;
// 	t_image		img;

// 	// set in main
// 	mlx_set_window(&mlx_ptr, &win_ptr, &wins, &img);

// 	// draw each point
// 	rgb.b = 0;
// 	rgb.g = 0;
// 	rgb.r = 255;
// 	for (int i = 0 ; i < img.image_width ; i++)
// 	{
// 		for (int j = 0 ; j < img.image_height; j++)
// 		{
// 			my_mlx_pixel_put(&wins, i, j, rgb);
// 		}	
// 	}

// 	// set in main
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, wins.img, 0, 0);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
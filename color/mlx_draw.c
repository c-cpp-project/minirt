#include "mlx_utility.h"

t_color	ray2color(t_ray_info ray_info, t_data data, double u, double v)
{
	t_ray		r;
	t_color		color;

	r = get_ray(scalar_multiply(data.view.viewport_h, u), \
	scalar_multiply(data.view.viewport_v, v), \
	data.co.origin, data.view.left_bottom);
	color = ray_color(ray_info, r);
	return (color);
}

void	ft_draw(t_ray_info ray_info, t_data data, t_mlx mlx_vars)
{
	int		j;
	int		i;
	double	u;
	double	v;
	t_color	color;

	j = data.image.image_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < data.image.image_width)
		{
			u = (double)i / (data.image.image_width - 1);
			v = (double)j / (data.image.image_height - 1);
			color = ray2color(ray_info, data, u, v);
			// printf("%d %d %d\n", (int)(color.r * 255.999), (int)(color.g * 255.999), (int)(color.b * 255.999));
			my_mlx_pixel_put(&(mlx_vars.wins), i, j, color);
			i++;
		}
		j--;
	}
}

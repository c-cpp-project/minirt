
# include "structure.h"
# include "parsing/parsing.h"
# include "parsing/__init__.h"
# include "color/mlx_utility.h"
#define PATH 1

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	t_count		element;
	t_mlx		mlx_vars;
	t_data		data;
	t_ray_info	ray_info;

	if (argc == 1)
		return (0);
	scene = parsing(argv[PATH], &element);
	__init__(&data, *(scene->c), argv, argc);
	mlx_set_window(&mlx_vars, &(data.image));
	ray_info.count = element;
	ray_info.scene = *scene;
	mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.win_ptr, \
	mlx_vars.wins.img, 0, 0);
	ft_draw(ray_info, data, mlx_vars);
	mlx_key_hook(mlx_vars.win_ptr, key_code_press, &mlx_vars);
	mlx_loop(mlx_vars.mlx_ptr);
	free_scene(scene);
	return (0);
}

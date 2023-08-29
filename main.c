#include "structure.h"
#include "parsing/parsing.h"
#include "parsing/__init__.h"
#include "color/mlx_utility.h"
#define PATH 1

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	t_count		element;
	t_mlx		mlx_vars;
	t_data		data;

	scene = parsing(argv[PATH], &element);
	__init__(&data, *(scene->c), argv, argc);
	mlx_set_window(mlx_vars.mlx_ptr, mlx_vars.win_ptr, &mlx_vars.wins, \
	&(data.image));
	// ========== execute ================ //
	mlx_put_image_to_window(mlx_vars.mlx_ptr, mlx_vars.win_ptr, \
	mlx_vars.wins.img, 0, 0);
	// =================================== //
	mlx_loop(mlx_vars.mlx_ptr);
	free_scene(scene);
}
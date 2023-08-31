

#include"__init__.h"

t_vector	turn180vector(t_vector vector1)
{
	t_vector	vector2;

	vector2.x = -vector1.x;
	vector2.y = -vector1.y;
	vector2.z = -vector1.z;
	return (vector2);
}

// lookup is vup
void	set_coordinate(t_camera cam, t_co *co)
{
	t_vector	lookup;

	co->origin = cam.position;
	lookup = new_vector(0, 1, 0);
	if (cam.dv.y != 0.0 && (cam.dv.x == 0 && cam.dv.z == 0))
		lookup = new_vector(0, 0, 1);
	co->horizontal = unit(cross_product(lookup, cam.dv));
	co->vertical = unit(cross_product(cam.dv, co->horizontal));
}

void	set_viewport(t_camera cam, t_view *view, t_co *co, t_image *img)
{
	double		theta;
	double		h;
	double		focal_length;
	t_vector	viewport_h;
	t_vector	viewport_v;

	theta = degrees_to_radians(cam.fov);
	h = tan(theta / 2);
	focal_length = 1.0;
	view->viewport_height = 2 * h * focal_length;
	view->viewport_width = img->aspect_ratio * view->viewport_height;
	viewport_h = scalar_multiply(co->horizontal, view->viewport_width);
	viewport_v = scalar_multiply(turn180vector(co->vertical), \
	view->viewport_height);
	view->left_bottom = getleft_bottom(co->origin, \
	viewport_h, viewport_v, cam.dv);
	view->viewport_h = viewport_h;
	view->viewport_v = viewport_v;
}

// vup is just view up about camera
void	__init__(t_data *data, t_camera cam, char *argv[], int argc)
{
	double	aspect_ratio;

	aspect_ratio = 16.0 / 9.0;
	data->image.image_width = 400;
	if (argc == 5)
	{
		aspect_ratio = ft_atoi(argv[WIDTH_RATIO]) / ft_atoi(argv[HEIGHT_RATIO]);
		data->image.image_width = ft_atoi(argv[WIDTH_IDX]);
	}
	data->image.image_height = (int) data->image.image_width / aspect_ratio;
	data->image.aspect_ratio = aspect_ratio;
	set_coordinate(cam, &(data->co));
	set_viewport(cam, &(data->view), &(data->co), &(data->image));
}

// example
// gcc set_view_port.c ../utils/*.c ../setting/view.c ft_math.c error_handle.c
// int	main(int argc, char *argv[])
// {
// 	t_data		data;
// 	t_camera	cam;

// 	// -- exampe cam -- //
// 	cam.dv = new_vector(0, 0, 1);
// 	cam.fov = 70;
// 	cam.position = new_vector(-50.0, 0, 20);
// 	// -----------------//
// 	__init__(&data, cam, argv, argc);
// 	// s_image
// 	printf("image: \n%.2lf %.2lf %.2lf\n", \
// 	data.image.image_height, data.image.image_width, data.image.aspect_ratio);
// 	// s_coordinate_system
// 	printf("coordinate: \n");
// 	print_vector(data.co.origin);
// 	print_vector(data.co.vertical);
// 	print_vector(data.co.horizontal);
// 	// s_view
// 	printf("view: \n");
//	print_vector(data.view.left_bottom);
// 	printf("%.2lf %.2lf %.2lf\n", data.view.viewport_height, \
// 	data.view.viewport_width, data.view.focal_length);
// 	return (0);
// }
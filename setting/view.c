#include "view.h"

t_ray get_ray(t_vector u_horizontal, t_vector v_vertical, t_vector origin, t_vector left_bottom) 
{
	t_ray	r;
	r = ray(origin, minus_vector(plus_vector(
		plus_vector(left_bottom, u_horizontal), v_vertical), origin));
	return (r);
}

t_vector getleft_bottom(t_vector origin, t_vector horizontal, t_vector vertical, t_vector focal_len_vector)
{
	t_vector result;
	return minus_vector(
	minus_vector(minus_vector(origin, 
	scalar_multiply(horizontal, 0.5)), scalar_multiply(vertical, 0.5)),
	focal_len_vector);
}

t_eye set_eye(t_scene scene, double aspect_ratio, t_vector look_at) {
	t_eye eye;
	double focal_len;
	//eye.focal_len = (float) WIDTH / 2 / tan(degrees_to_radians(scene.c.fov) / 2);
	double theta = degrees_to_radians(scene.c.fov);
	eye.view_height = 2.0 * tan(theta / 2);
	eye.view_width = aspect_ratio * eye.view_height;
	// eye.focal_len = 1.0;

	t_vector w = unit(minus_vector(eye.origin, look_at));
	t_vector u = unit(cross_product(scene.c.dv, w));
	t_vector v = cross_product(w, u);
	eye.origin = scene.c.position;
	eye.horizontal = scalar_multiply(u, eye.view_width);
	eye.vertical = scalar_multiply(v, eye.view_height);
	eye.left_bottom = getleft_bottom(eye.origin, eye.horizontal, eye.vertical, w);
	return eye;
}

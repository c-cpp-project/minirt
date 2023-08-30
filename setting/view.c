#include "view.h"

t_ray	get_ray(t_vector u_horizontal, t_vector v_vertical,
	t_vector origin, t_vector left_bottom)
{
	t_ray	r;

	r = ray(origin, minus_vector(plus_vector(plus_vector(left_bottom,
						u_horizontal), v_vertical), origin));

	return (r);
}

t_vector	getleft_bottom(t_vector origin, t_vector horizontal,
	t_vector vertical, t_vector focal_len_vector)
{

	return (minus_vector(
			minus_vector(minus_vector(origin, scalar_multiply(horizontal, 0.5)),
				scalar_multiply(vertical, 0.5)), focal_len_vector));
}
#include "../setting/view.h"

t_color	ray_color(t_ray_info ray_info, t_ray ray)
{
	t_hit_record	record;
	t_vector		direction;
	double			t;

	record = hit_world(ray_info, ray, 1e-6, INF);
	t = record.t;
	if (t > 1e-6)
	{
		return (phong_ligthing(ray_info, record, ray));
	}
	direction = ray.dv;
	t = 0.5 * (direction.y + 1.0);
	return (plus_color(multiply_color(new_color(1.0, 1.0, 1.0), 1.0 - t),
			multiply_color(new_color(0.0, 0.0, 1.0), t)));
}
#include "../setting/view.h"

t_color ray_color(t_ray ray, t_scene scene, t_count count)
{
	t_hit_record record = hit_world(scene, count, ray, 0, INF);
	double t = record.t;
	if (t > 0.0) {      
		t_vector vector_n = unit(minus_vector(ray_at(&ray, t), scene.cl[0].center));
        t_vector direction = random_vector_from_surface(record.normal);
        return phong_ligthing(scene, count, record, ray);
        return multiply_color(new_color(record.normal.x * 0.5 + 1, record.normal.y * 0.5 + 1, record.normal.z * 0.5 + 1), 0.5);
	}
	t_vector direction = ray.dv;
	t = 0.5 * (direction.y + 1.0);
	return plus_color(multiply_color(new_color(1.0, 1.0, 1.0), 1.0  - t), multiply_color(new_color(0.0, 0.0, 0.0), t));
}
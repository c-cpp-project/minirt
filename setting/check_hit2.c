#include "view.h"

t_hit_record	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_hit_record	record;
	double			a;
	double			b;
	double			c;
	t_vector		co;

	co = minus_vector(ray.origin, sphere.center);
	a = inner_product(ray.dv, ray.dv);
	b = 2.0 * inner_product(co, ray.dv);
	c = inner_product(co, co) - sphere.radius * sphere.radius;

	record.t = positive_min_root_two_degree(a, b, c);
	record.pos = ray_at(&ray, record.t);
	record.normal = unit(minus_vector(record.pos, sphere.center));
	record.object_color = sphere.color;
	return (record);
}

t_hit_record	hit_plane(t_plane plane, t_ray ray)
{
	t_hit_record	record;
	double			b;
	double			c;
	t_vector		po;

	po = minus_vector(ray.origin, plane.point);
	b = inner_product(ray.dv, plane.dv);
	c = -inner_product(po, plane.dv);

	record.t = positive_min_root_one_degree(b, c);
	record.pos = ray_at(&ray, record.t);
	record.object_color = plane.color;
	if (inner_product(record.pos, plane.dv) < 0)
		record.normal = plane.dv;
	else
		record.normal = scalar_multiply(plane.dv, -1.0);
	return (record);
}

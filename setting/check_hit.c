#include "view.h"

void	get_cylinder_side_normal(t_hit_record *record, t_cylinder cylinder)
{
	record->normal = unit(minus_vector(record->pos,
				plus_vector(cylinder.center,
					scalar_multiply(cylinder.dv,
						inner_product(minus_vector(record->pos,
								cylinder.center), cylinder.dv)))));
}

t_hit_record	hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	t_hit_record	record;
	double			t1;
	double			t2;
	double			t3;
	double			t;

	t1 = hit_cylinder_cap(cylinder, ray, cylinder.bottom);
	t2 = hit_cylinder_cap(cylinder, ray, cylinder.top);
	t3 = hit_cylinder_side(cylinder, ray);

	t = positive_min_2(positive_min_2(t1, t2), t3);
	record.t = t;
	record.pos = ray_at(&ray, t);
	record.object_color = cylinder.color;
	if (t == t3)
		get_cylinder_side_normal(&record, cylinder);
	if (t == t1)
		record.normal = unit(minus_vector(cylinder.bottom, cylinder.center));
	if (t == t2)
		record.normal = unit(minus_vector(cylinder.top, cylinder.center));
	return (record);
}

double	get_t_of_cylinder_side(t_cylinder cylinder, double t, t_ray ray)
{
	t_vector	vector;

	if (t < 0)
		return (-1.0);
	vector = ray_at(&ray, t);
	if (fabs(inner_product(minus_vector(vector, cylinder.center), cylinder.dv))
		<= cylinder.height / 2)
		return (t);
	return (-1.0);
}

double	hit_cylinder_side(t_cylinder cylinder, t_ray ray)
{
	t_vector	co;
	double		a;
	double		b;
	double		c;
	double		t;

	co = minus_vector(ray.origin, cylinder.center);
	a = inner_product(cross_product(ray.dv, cylinder.dv),
			cross_product(ray.dv, cylinder.dv));
	b = 2 * inner_product(cross_product(ray.dv, cylinder.dv),
			cross_product(co, cylinder.dv));
	c = inner_product(cross_product(co, cylinder.dv),
			cross_product(co, cylinder.dv))
		- cylinder.radius * cylinder.radius;
	t = positive_min_root_two_degree(a, b, c);
	return (get_t_of_cylinder_side(cylinder, t, ray));
}

double	hit_cylinder_cap(t_cylinder cylinder, t_ray ray, t_vector cap_center)
{
	double		b;
	double		c;
	t_vector	co;
	t_vector	vector;

	co = minus_vector(ray.origin, cap_center);
	b = inner_product(ray.dv, cylinder.dv);
	c = -inner_product(co, cylinder.dv);
	if (c / b < 0)
		return (-1.0);
	vector = ray_at(&ray, c / b);
	if (inner_product(minus_vector(vector, cap_center),
			minus_vector(vector, cap_center))
		<= cylinder.radius * cylinder.radius)
		return (c / b);
	return (-1.0);
}

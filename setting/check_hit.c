#include "view.h"

t_hit_record	hit_cylinder(t_cylinder cylinder, t_ray ray)
{
	t_hit_record record;
	double	t1 = hit_cylinder_cap(cylinder, ray, cylinder.bottom);
	double	t2 = hit_cylinder_cap(cylinder, ray, cylinder.top);
	double	t3 = hit_cylinder_side(cylinder, ray);
	double	t;

	t = positive_min_2(positive_min_2(t1, t2), t3);
	record.t = t;
	record.pos = ray_at(&ray, t);
	record.object_color = cylinder.color;
	if (t == t3)
	{
		t_vector vector = minus_vector(record.pos, cylinder.center);
		// t_vector vector2 = scalar_multiply(cylinder.dv, inner_product(vector, cylinder.dv));
		record.normal = unit(minus_vector(vector, new_vector(0, 0, 0)));
		// record.normal = unit(minus_vector(record.pos, plus_vector(cylinder.center, scalar_multiply(cylinder.dv, 
		// inner_product(minus_vector(record.pos, cylinder.center), cylinder.dv)))));
	}
	if (t == t1)
		record.normal = unit(minus_vector(cylinder.bottom, cylinder.center));
	else
		record.normal = unit(minus_vector(cylinder.top, cylinder.center));
	return record;
}

double hit_cylinder_side(t_cylinder cylinder, t_ray ray) {
	t_vector co;
	t_vector vector; 
	double a;
	double b;
	double c;

	co = minus_vector(ray.origin, cylinder.center);
	a = inner_product(cross_product(ray.dv, cylinder.dv), cross_product(ray.dv, cylinder.dv));
	b = 2 * inner_product(cross_product(ray.dv, cylinder.dv), cross_product(co, cylinder.dv));
	c = inner_product(cross_product(co, cylinder.dv), cross_product(co, cylinder.dv))
		- cylinder.radius * cylinder.radius;
	double t = positive_min_root_two_degree(a, b, c);
	if (t < 0)
		return (-1.0);
	vector = ray_at(&ray, t);
	if (fabs(inner_product(minus_vector(vector, cylinder.center), cylinder.dv)) <= cylinder.height / 2 ) {
		return (t);
	}
	return (-1.0);
}

double hit_cylinder_cap(t_cylinder cylinder, t_ray ray, t_vector cap_center) {
	double b;
	double c;
	t_vector co;
	t_vector vector;

	co = minus_vector(ray.origin, cap_center);
	b = inner_product(ray.dv , cylinder.dv);
	c = - inner_product(co, cylinder.dv);
	if (c / b < 0)
		return (-1.0);
	vector = ray_at(&ray, c / b);	
	if (inner_product(minus_vector(vector, cap_center) , 
		minus_vector(vector, cap_center)) <= cylinder.radius * cylinder.radius)
		return c / b;
	return -1.0;
}

t_hit_record	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_hit_record record;
	t_vector co = minus_vector(ray.origin, sphere.center);
	double a = inner_product(ray.dv, ray.dv);
	double b = 2.0 * inner_product(co, ray.dv);
	double c = inner_product(co, co) - sphere.radius * sphere.radius;

	record.t = positive_min_root_two_degree(a, b, c);
	record.pos = ray_at(&ray, record.t);
	record.normal = unit(minus_vector(record.pos, sphere.center));
	record.object_color = sphere.color;
	return record;
}

t_hit_record	hit_plane(t_plane plane, t_ray ray) {
	t_hit_record record;
	double b;
	double c;
	t_vector po; 

	po = minus_vector(ray.origin, plane.point);
	b = inner_product(ray.dv , plane.dv);
	c = - inner_product(po, plane.dv);

	record.t = positive_min_root_one_degree(b, c);
	record.pos = ray_at(&ray, record.t);
	record.object_color = plane.color;
	if (inner_product(record.pos, plane.dv) < 0)
		record.normal = plane.dv;
	else
		record.normal = scalar_multiply(plane.dv, -1.0);
	return record;
}
#include "view.h"

double hit_world(t_scene scene) {
	return 0.0;
}

double hit_sphere(t_sphere sphere, t_ray ray)
{
	t_vector oc = minus_vector(ray.origin, sphere.center);
	double a = inner_product(ray.dv, ray.dv);
	double b = 2.0 * inner_product(oc, ray.dv);
	double c = inner_product(oc, oc) - sphere.radius * sphere.radius;
	double discriminant = b * b - 4 * a * c;
	// print_vector(ray.dv);
	if (discriminant < 0) {
		return -1.0;
	}
	return (-b - sqrt(discriminant)) / (2.0 * a);
}
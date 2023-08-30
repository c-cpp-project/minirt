#include "ray.h"

t_ray	ray(t_vector origin, t_vector dv)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dv = unit(dv);
	return (ray);
}

t_vector	ray_at(t_ray *ray, double t)
{
	t_vector	result;

	result = plus_vector(ray->origin, scalar_multiply(ray->dv, t));
	return (result);
}
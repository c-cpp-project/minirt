#include "../setting/view.h"

int	in_shadow(t_ray_info ray_info, t_ray light_ray, double light_len)
{
	t_hit_record	record;

	record = hit_world(ray_info, light_ray, 1e-6, light_len);
	if (record.t == -1.0)
	{
		return (0);
	}
	return (1);
}

t_color	get_specular(t_ray object_ray, t_vector to_light,
	t_hit_record record, t_light light)
{
	t_vector	view_dv;
	t_vector	reflect_dv;
	double		ksn;
	double		ks;
	double		spec;

	ksn = 64;
	ks = 0.5;

	view_dv = unit(scalar_multiply(object_ray.dv, -1));
	reflect_dv = reflect_vector(scalar_multiply(to_light, 1), record.normal);
	spec = pow(max_2(inner_product(view_dv, reflect_dv), 0.0), ksn);
	return (multiply_color(multiply_color(light.color, ks), spec));
}

t_color	get_color_of_point(t_light light, t_hit_record record, t_ray object_ray,
	t_ray_info ray_info) {
	t_vector	to_light;
	t_color		diffuse;
	double		light_len;
	double		kd;
	t_ray		light_ray;

	to_light = unit(minus_vector(light.position, record.pos));
	light_len = len(to_light);
	light_ray = ray(plus_vector(record.pos,
				scalar_multiply(record.normal, 1e-6)), to_light);
	if (in_shadow(ray_info, light_ray, light_len))
		return (new_color(0, 0, 0));
	kd = max_2(inner_product(to_light, record.normal), 0.0);
	diffuse = multiply_color(light.color, kd);
	return (plus_color(diffuse,
			get_specular(object_ray, to_light, record, light)));
}

t_color	phong_ligthing(t_ray_info ray_info, t_hit_record record, t_ray ray)
{
	t_color	light_color;
	int		i;

	light_color = new_color(0, 0, 0);
	i = -1;
	while (++i < ray_info.count.light)
	{
		light_color = plus_color(light_color,
				get_color_of_point(ray_info.scene.l[i], record, ray, ray_info));
	}
	light_color = plus_color(light_color, ray_info.scene.a[0].color);
	return (color_min((multiply_light(light_color, record.object_color)),
			new_color(1, 1, 1)));
}

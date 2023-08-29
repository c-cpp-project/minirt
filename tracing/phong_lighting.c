#include "../setting/view.h"

int	in_shadow(t_scene scene, t_ray light_ray, double light_len, t_count count)
{
	t_hit_record record;

	record = hit_world(scene, count, light_ray, 1e-6, light_len);
	if (record.t == -1.0) {
		return (0);
	}
	return (1);
}


t_color get_color_of_point(t_light light, t_hit_record record, t_ray object_ray, t_scene scene, t_count count) {
	t_vector to_light;
	t_color diffuse;
	double light_len;
	double kd;
	t_ray	light_ray;

	to_light = unit(minus_vector(light.position, record.pos));
	light_len = len(to_light);
	light_ray = ray(plus_vector(record.pos, scalar_multiply(record.normal, EPSILON)), to_light);
	if (in_shadow(scene, light_ray, light_len, count)) {
		return new_color(0, 0, 0);
	}
	kd = max_2(inner_product(to_light ,record.normal), 0.0);
	diffuse = multiply_color(light.color, kd);//수정 필요

	t_vector view_dv;
	t_vector reflect_dv;
	double ksn = 64;
	double ks = 0.5;
	view_dv = unit(scalar_multiply(object_ray.dv, -1));
	reflect_dv = reflect_vector(scalar_multiply(to_light, 1), record.normal);//주의
	double spec = pow(max_2(inner_product(view_dv, reflect_dv), 0.0), ksn);
	t_color specular = multiply_color(multiply_color(light.color, ks), spec);
	return plus_color(diffuse, specular);
}

t_color	phong_ligthing(t_scene scene, t_count counts, t_hit_record record, t_ray ray)
{
	t_color	light_color;
	int		i;

	light_color = new_color(0, 0, 0);
	i = -1;
	while (++i < counts.light) {
		light_color = plus_color(light_color, get_color_of_point(scene.l[i], record, ray, scene, counts));
	}
	light_color = plus_color(light_color, scene.a[0].color);
	return color_min((multiply_light(light_color, record.object_color)), new_color(1, 1, 1));
}

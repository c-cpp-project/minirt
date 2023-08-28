#include "../setting/view.h"

// t_color get_speculaer(t_light, t_hit_record record) {
// 	t_vector view_dv;
// 	t_vector reflect_dv;
// 	t_color specular;
// 	// view_dv = record.
// }


t_color get_color_of_point(t_light light, t_hit_record record, t_ray ray) {
	t_vector to_light;
	t_color diffuse;
	double kd;

	to_light = unit(minus_vector(light.position, record.pos));
	kd = max_2(inner_product(to_light ,record.normal), 0.0);
	diffuse = multiply_color(light.color, kd);//수정 필요

	t_vector view_dv;
	t_vector reflect_dv;
	double ksn = 64;
	double ks = 0.5;
	view_dv = unit(scalar_multiply(ray.dv, -1));
	reflect_dv = reflect_vector(scalar_multiply(to_light, -1), record.normal);//주의
	
	return (diffuse);
}

//수정 필요 아주 꼼꼼히 봐야 함
t_color	phong_ligthing(t_scene scene, t_count counts, t_hit_record record)
{
	t_color	light_color;
	int		i;

	light_color = new_color(0, 0, 0);
	i = -1;
	while (++i < counts.light) {
		light_color = plus_color(light_color, get_color_of_point(scene.l[i], record));
	}
	light_color = plus_color(light_color, scene.a[0].color);
	return color_min((multiply_light(light_color, record.object_color)), new_color(1, 1, 1));
}

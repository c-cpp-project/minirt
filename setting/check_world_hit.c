#include "view.h"

t_hit_record hit_world(t_scene scene, t_count count, t_ray ray, double t_min, double t_max) {
    t_hit_record    record;
    t_hit_record    result;
    int i;
    i = -1;
    result.t = -1;
    while (++i < count.cylinder)
    {
        record = hit_cylinder(scene.cl[i], ray);
        if (current_min(record.t, result.t, t_min, t_max)) {
            result = record;
        }
    }
    i = -1;
    while (++i < count.sphere)
    {
        record = hit_sphere(scene.sp[i], ray);
        if (current_min(record.t, result.t, t_min, t_max)) {
            result = record;
        }
    }
    i = -1;
    while (++i < count.plane)
    {
        record = hit_plane(scene.pl[i], ray);
        if (current_min(record.t, result.t, t_min, t_max)) {
            result = record;
        }
    }
	return record;
}



int current_min(double target, double compared, double t_min, double t_max) {
    if (target < t_min || target > t_max)
        return (0);
    if (compared < t_min || compared > t_max)
        return (1);
    if (compared < target) {
        return (0);
    }
    return (1);
}

double min_of_set(double num1, double num2, double t_min, double t_max) {
    if (num1 < t_min || num1 > t_max)
        return (num2);
    if (num1 < t_min || num1 > t_max)
        return (num1);
    return min_2(num1, num2);
}

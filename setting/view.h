#ifndef VIEW_H
# define VIEW_H
# include "../structure.h"
# include "../parsing/parsing.h"

# define WIDTH 300
# define HEIGHT 150

# define EPSILON 1e-6
# define LUMEN 3

typedef struct s_ray_info{
	t_count	count;
	t_scene	scene;
}	t_ray_info;

typedef struct s_hit_record
{
	double		t;
	t_vector	pos;
	t_vector	normal;
	t_color		object_color;
}	t_hit_record;

t_ray			get_ray(t_vector u_horizontal, t_vector v_vertical,
					t_vector origin, t_vector left_bottom);
t_hit_record	hit_sphere(t_sphere sphere, t_ray ray);
t_hit_record	hit_cylinder(t_cylinder cylinder, t_ray ray);
double			hit_cylinder_side(t_cylinder cylinder, t_ray ray);
double			hit_cylinder_cap(t_cylinder cylinder,
					t_ray ray, t_vector cap_center);
t_hit_record	hit_plane(t_plane plane, t_ray ray);
t_hit_record	hit_world(t_ray_info ray_info, t_ray ray,
					double t_min, double t_max);
int				current_min(double target, double compared,
					double t_min, double t_max);
t_color			phong_ligthing(t_ray_info ray_info,
					t_hit_record record, t_ray ray);
t_color			ray_color(t_ray_info ray_info, t_ray ray);

#endif
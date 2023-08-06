#ifndef VIEW_H
# define VIEW_H
#include "../structure.h"

#define WIDTH 300
#define HEIGHT 150

typedef struct s_eye
{
	t_vector	origin;
	double		view_height;
	double		view_width;
	t_vector	horizontal;
	t_vector	vertical;
	double		focal_len;
	t_vector	left_bottom;
}	t_eye;

typedef struct s_viewport
{
	int		width;
	int		height;
}	t_viewport;
//canvas와 동일하게?

t_ray get_ray(t_vector u_horizontal, t_vector v_vertical, t_vector origin, t_vector left_bottom);
t_vector getleft_bottom(t_vector origin, t_vector horizontal, t_vector vertical, t_vector focal_len_vector);

//check_hit.c
double hit_sphere(t_sphere sphere, t_ray ray);
double hit_cylinder(t_cylinder cylinder, t_ray ray);
double hit_cylinder_side(t_cylinder cylinder, t_ray ray);
double hit_cylinder_cap(t_cylinder cylinder, t_ray ray, t_vector cap_center);
double hit_plane(t_plane plane, t_ray ray);

//cylinder 설정
void add_top_and_bottom_vector(t_cylinder *cylinder);

#endif
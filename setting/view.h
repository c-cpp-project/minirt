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

#endif
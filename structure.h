#ifndef STRUCTURE_H
# define STRUCTURE_H

#include "utils/utils.h"

typedef struct s_ambient
{
	double	ratio;
	t_color color;
}t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	dv;// normalization orientation vector, 벡터 크기 1로 받기
	double		fov;//시야각 0 ~ 180도
}t_camera;

typedef struct s_light
{
	t_vector position;
	double ratio;
	t_color color;
}	t_light;

typedef struct s_sphere
{
	t_vector center;
	double radius; // diameter 지름 2로 나눈 값
	t_color color;
}	t_sphere;

typedef struct s_plane
{
	t_vector point;
	t_vector dv; // 법선 벡터, normalized normal vector 벡터 크기 1로 받기
	t_color color;
}	t_plane;

typedef struct s_cylinder{
	t_vector center;
	t_vector dv; //normalized vector of axis of cylinder, 벡터 크기 1로 받기
	double radius; // diameter 지름 2로 나눈 값
	double height;
	t_color color;
}	t_cylinder;

typedef struct s_scene{
	t_ambient	a;
	t_camera	c;
	t_light		l;
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cl;
}	t_scene;

#endif
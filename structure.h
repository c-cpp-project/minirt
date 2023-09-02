/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:40:45 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 13:43:16 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "utils/ray.h"

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}t_ambient;

typedef struct s_camera
{
	t_vector	position;
	t_vector	dv;
	double		fov;
}t_camera;

typedef struct s_light
{
	t_vector	position;
	double		ratio;
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_vector	center;
	double		radius;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	point;
	t_vector	dv;
	t_color		color;
}	t_plane;

typedef struct s_cylinder{
	t_vector	center;
	t_vector	dv;
	double		radius;
	double		height;
	t_color		color;
	t_vector	top;
	t_vector	bottom;
}	t_cylinder;

typedef struct s_scene{
	t_ambient	*a;
	t_camera	*c;
	t_light		*l;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cl;
}	t_scene;

#endif
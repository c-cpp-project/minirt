/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:40:20 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 13:40:20 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "utils.h"

typedef struct s_ray
{
	t_vector	origin;
	t_vector	dv;
}	t_ray;

t_ray		ray(t_vector origin, t_vector dv);
t_vector	ray_at(t_ray *ray, double t);

#endif
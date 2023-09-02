/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:39:50 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 13:53:20 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color	new_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	plus_color(t_color color1, t_color color2)
{
	color1.r += color2.r;
	color1.g += color2.g;
	color1.b += color2.b;
	return (color1);
}

t_color	multiply_color(t_color color, double t)
{
	color.r *= t;
	color.g *= t;
	color.b *= t;
	return (color);
}

t_color	multiply_light(t_color color1, t_color color2)
{
	color1.r *= color2.r;
	color1.g *= color2.g;
	color1.b *= color2.b;
	return (color1);
}

void	print_color(t_color color)
{
	printf("%f %f %f\n", color.r, color.g, color.b);
}

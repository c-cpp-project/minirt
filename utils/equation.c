/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:39:56 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 13:46:51 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	positive_min_root_one_degree(double b, double c)
{
	if (b == 0)
	{
		return (-1.0);
	}
	if (c / b > 0)
	{
		return (c / b);
	}
	return (-1.0);
}

double	positive_min_root_two_degree(double a, double b, double c)
{
	double	discriminant;
	double	root;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return (-1.0);
	}
	root = (-b - sqrt(discriminant)) / (2.0 * a);
	if (root > 0)
	{
		return (root);
	}
	root = (-b + sqrt(discriminant)) / (2.0 * a);
	if (root > 0)
	{
		return (root);
	}
	return (-1.0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:38:17 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 13:38:31 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_top_and_bottom_vector(t_cylinder *cylinder)
{
	t_vector	dh;

	dh = scalar_multiply(cylinder->dv, cylinder->height * 0.5);
	cylinder->top = plus_vector(cylinder->center, dh);
	cylinder->bottom = minus_vector(cylinder->center, dh);
}

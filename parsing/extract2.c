/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:40:26 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/27 16:40:18 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

t_cylinder	*extract_cylinder(char **buffer, t_count *element)
{
	t_cylinder	*node;
	char		**value;
	int			i;
	int			j;
	int			idx;

	node = (t_cylinder *)malloc(sizeof(t_cylinder) * (element->cylinder + 1));
	i = 0;
	idx = 0;
	while (buffer[i] && idx < element->cylinder)
	{
		if (ft_strncmp(buffer[i], "cy", 2) == 0)
		{
			value = ft_split_group(buffer[i], TRUE);
			node[idx].center = get_vector(value[1], FALSE);
			node[idx].dv = unit(get_vector(value[2], TRUE));
			node[idx].radius = ft_atol(value[3]) / 2;
			node[idx].height = ft_atol(value[4]);
			node[idx].color = get_color(value[5]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}
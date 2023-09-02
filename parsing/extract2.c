/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:38:42 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 14:00:46 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

t_cylinder	*extract_cylinder(char **buffer, t_count *element)
{
	t_cylinder	*node;
	char		**value;
	int			i;
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
			add_top_and_bottom_vector(&node[idx]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}

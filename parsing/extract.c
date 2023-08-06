/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:30:11 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/05 19:40:45 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

t_ambient	*extract_ambient(char **buffer, t_count *element)
{
	t_ambient	*node;
	char		**value;
	int			i;
	int			j;
	int			idx;

	node = (t_ambient *)malloc(sizeof(t_ambient) * element->ambient);
	i = 0;
	idx = 0;
	while (buffer[i] && idx < element->ambient)
	{
		if (ft_strncmp(buffer[i], "A", 1) == 0)
		{
			value = ft_split(buffer[i], ' ');
			node[idx].ratio = ft_atol(value[1]);
			node[idx].color = get_color(value[2]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}

t_camera	*extract_camera(char **buffer, t_count *element)
{
	t_camera	*node;
	char		**value;
	int			i;
	int			j;
	int			idx;

	node = (t_camera *)malloc(sizeof(t_camera) * element->camera);
	i = 0;
	idx = 0;
	while (buffer[i] && idx < element->camera)
	{
		if (ft_strncmp(buffer[i], "C", 1) == 0)
		{
			value = ft_split(buffer[i], ' ');
			node[idx].position = get_vector(value[1]);
			node[idx].dv = unit(get_vector(value[2]));
			node[idx].fov = ft_atol(value[3]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}

t_light	*extract_light(char **buffer, t_count *element)
{
	t_light		*node;
	char		**value;
	int			i;
	int			j;
	int			idx;

	node = (t_light *)malloc(sizeof(t_light) * element->light);
	i = 0;
	idx = 0;
	while (buffer[i] && idx < element->light)
	{
		if (ft_strncmp(buffer[i], "L", 1) == 0)
		{
			value = ft_split(buffer[i], ' ');
			node[idx].position = get_vector(value[1]);
			node[idx].ratio = ft_atol(value[2]);
			node[idx].color = get_color(value[3]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}

t_sphere	*extract_sphere(char **buffer, t_count *element)
{
	t_sphere	*node;
	char		**value;
	int			i;
	int			j;
	int			idx;

	node = (t_sphere *)malloc(sizeof(t_sphere) * element->sphere);
	i = 0;
	idx = 0;
	while (buffer[i] && idx < element->sphere)
	{
		if (ft_strncmp(buffer[i], "A", 1) == 0)
		{
			value = ft_split(buffer[i], ' ');
			node[idx].center = get_vector(value[1]);
			node[idx].radius = ft_atol(value[2]) / 2;
			node[idx].color = get_color(value[3]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}

t_plane	*extract_plane(char **buffer, t_count *element)
{
	t_plane		*node;
	char		**value;
	int			i;
	int			j;
	int			idx;

	node = (t_plane *)malloc(sizeof(t_plane) * element->plane);
	i = 0;
	idx = 0;
	while (buffer[i] && idx < element->plane)
	{
		if (ft_strncmp(buffer[i], "A", 1) == 0)
		{
			value = ft_split(buffer[i], ' ');
			node[idx].point = get_vector(value[1]);
			node[idx].dv = unit(get_vector(value[2]));
			node[idx].color = get_color(value[3]);
			free_split(value);
			idx++;
		}
		i++;
	}
	return (node);
}
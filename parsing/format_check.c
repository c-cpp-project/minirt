/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:00:26 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/06 15:20:01 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	parameter_init(t_count *element)
{
	element->ambient = 0;
	element->camera = 0;
	element->light = 0;
	element->plane = 0;
	element->cylinder = 0;
}

void	parameter_format(char *line, t_count *element, char *mode)
{
	char	**feature;
	int		length;
	int		error;

	feature = ft_split(line, ' ');
	error = FALSE;
	length = 0;
	while (feature[length])
		length++;
	if (*mode == 'A' && length != 3)
		put_error("paramater_format A");
	if (*mode == 'C' && length != 4)
		put_error("paramater_format A");
	if (*mode == 'L' && length != 4)
		put_error("paramater_format A");
	if (ft_strncmp(mode, "pl", 2) == 0 && length != 4)
		put_error("paramater_format A");
	if (ft_strncmp(mode, "sp", 2) == 0 && length != 4)
		put_error("paramater_format A");
	if (ft_strncmp(mode, "cy", 2) == 0 && length != 6)
		put_error("paramater_format A");
	free_split(feature);
}

void	parameter_count(char **buffer, t_count *element)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (ft_strncmp(buffer[i], "A", 1) == 0)
			element->ambient++;
		else if (ft_strncmp(buffer[i], "C", 1) == 0)
			element->camera++;
		else if (ft_strncmp(buffer[i], "L", 1) == 0)
			element->light++;
		else if (ft_strncmp(buffer[i], "pl", 2) == 0)
			element->plane++;
		else if (ft_strncmp(buffer[i], "sp", 2) == 0)
			element->sphere++;
		else if (ft_strncmp(buffer[i], "cy", 2) == 0)
			element->cylinder++;
		else
			put_error("paramater_count wrong mode");
		parameter_format(buffer[i], element, buffer[i]);
		i++;
	}
	// printf("%d %d %d %d %d %d\n", element->ambient, element->camera, element->light, element->plane, element->sphere, element->cylinder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:28:54 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/27 16:17:11 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"
#define BUFFER_SIZE 32

char	*write_buffer(int fd)
{
	char	buffer[BUFFER_SIZE];
	size_t	length;
	size_t	tmp;
	char	*src;
	char	*dest;

	dest = 0;
	length = 0;
	tmp = read(fd, buffer, BUFFER_SIZE);
	src = (char *)malloc(sizeof(char));
	src[0] = 0;
	while (TRUE)
	{
		length += tmp;
		dest = ft_strdup(src, length);
		ft_strlcat(dest, buffer, length + 1);
		if (tmp != BUFFER_SIZE)
			break ;
		tmp = read(fd, buffer, BUFFER_SIZE);
		src = dest;
	}
	dest[length] = 0;
	return (dest);
}

void	put_error(char *msg)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, msg, ft_strlen(msg));
	exit(1);
}

t_scene	*parsing(const char *path, t_count *element)
{
	int		fd;
	char	*src;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(0);
	src = write_buffer(fd);
	return (assign_scene(src, element));
}

// read buffer
// parameter_count: 1. check identifier 2. check parameter count of identifier
t_scene	*tokenizer(char **buffer, t_count *element)
{
	t_scene	*scene;
	int		i;
	char	**split_space;

	parameter_init(element);
	i = 0;
	while (buffer[i])
	{
		split_space = ft_split_group(buffer[i], TRUE);
		parameter_count(split_space[0], element);
		parameter_format(split_space, split_space[0]);
		free_split(split_space);
		i++;
	}
	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->a = extract_ambient(buffer, element);
	scene->c = extract_camera(buffer, element);
	scene->l = extract_light(buffer, element);
	scene->pl = extract_plane(buffer, element);
	scene->sp = extract_sphere(buffer, element);
	scene->cl = extract_cylinder(buffer, element);
	return (scene);
}

t_scene	*assign_scene(char *src, t_count *element)
{
	char	**buffer;
	t_scene	*scene;

	buffer = ft_split(src, '\n');
	scene = tokenizer(buffer, element);
	free_split(buffer);
	return (scene);
}

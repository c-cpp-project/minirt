/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:28:54 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/06 14:22:38 by sangwoki         ###   ########.fr       */
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
	// printf("dest \n\n[%s]", dest);
	return (dest);
}


void	put_error(char *msg)
{
	perror(msg);
	exit(0);
}

t_scene	*parsing(const char *path, t_count *element)
{
	int		fd;
	char	*src;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(0);
	src = write_buffer(fd);
	return (assigne_scene(src, element));
}

// read buffer
// parameter_count: 1. check identifier 2. check parameter count of identifier
// 

t_scene	*tokenizer(char **buffer, t_count *element)
{
	t_scene	*scene;

	parameter_init(element);
	parameter_count(buffer, element);
	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->a = extract_ambient(buffer, element);
	scene->c = extract_camera(buffer, element);
	scene->l = extract_light(buffer, element);
	scene->pl = extract_plane(buffer, element);
	scene->sp = extract_sphere(buffer, element);
	scene->cl = extract_cylinder(buffer, element);
	return (scene);
}

t_scene	*assigne_scene(char *src, t_count *element)
{
	char	**buffer;
	t_scene	*scene;

	buffer = ft_split(src, '\n');
	element = (t_count *)malloc(sizeof(t_count));
	scene = tokenizer(buffer, element);
	return (scene);
}
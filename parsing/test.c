/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:02:12 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/06 15:39:54 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define PATH 1

void	put_color(t_color color, char *msg)
{
	printf("%s = [R: %lf, G: %lf, B: %lf]\n", msg, color.r, color.g, color.b);
}

void	put_vector(t_vector vector, char *msg)
{
	printf("%s = [X: %lf, Y: %lf, Z: %lf]\n", msg, vector.x, vector.y, vector.z);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_count element; // 개수
	int		i;

	scene = parsing(argv[PATH], &element);
	i = 0;
	printf("ambient\n\n");
	while (i < element.ambient)
	{
		put_color((scene->a)[i].color, "ambient color");
		printf("ambient ratio: %lf\n", (scene->a)[i].ratio);
		printf("\n");
		i++;
	}
	printf("camera\n\n");
	i = 0;
	while (i < element.camera)
	{
		put_vector((scene->c)[i].position, "camera position");
		put_vector((scene->c)[i].dv, "camera dv");
		printf("camera fov: %lf\n", (scene->c)[i].fov);
		printf("\n");
		i++;
	}
	printf("light\n\n");
	i = 0;
	while (i < element.light)
	{
		put_vector((scene->l)[i].position, "light position");
		printf("light ratio: %lf\n", (scene->l)[i].ratio);
		put_color((scene->l)[i].color, "light color");
		printf("\n");
		i++;
	}
	i = 0;
	printf("sphere\n\n");
	while (i < element.sphere)
	{
		put_vector((scene->sp)[i].center, "sphere position");
		printf("sphere ratio: %lf\n", (scene->sp)[i].radius);
		put_color((scene->sp)[i].color, "sphere color");
		printf("\n");
		i++;
	}
	i = 0;
	printf("plane\n\n");
	while (i < element.plane)
	{
		put_vector((scene->pl)[i].point, "plane position");
		put_vector((scene->pl)[i].dv, "plane dv");
		put_color((scene->pl)[i].color, "plane color");
		printf("\n");
		i++;
	}
	i = 0;
	printf("cylinder\n\n");
	while (i < element.cylinder)
	{
		put_vector((scene->cl)[i].center, "cylinder position");
		put_vector((scene->cl)[i].dv, "cylinder dv");
		printf("cylinder radius: %lf\n", (scene->cl)[i].radius);
		printf("cylinder height: %lf\n", (scene->cl)[i].height);
		put_color(scene->cl->color, "cylinder color");
		printf("\n");
		i++;
	}
	//실행 함수
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:39:13 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 14:02:57 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	free_scene(t_scene *scene)
{
	free(scene->a);
	free(scene->c);
	free(scene->cl);
	free(scene->l);
	free(scene->pl);
	free(scene->sp);
	free(scene);
}

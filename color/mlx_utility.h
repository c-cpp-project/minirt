/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utility.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:00:48 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/28 16:01:49 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILITY_H
# define MLX_UTILITY_H
# define TRUE 1
# define FALSE 0
# define RED 0
# define GREEN 1
# define BLUE 2
# define X 0
# define Y 1
# define Z 2

# include"../structure.h"
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<math.h>

// mlx_color.c
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

#endif MLX_UTILITY_H
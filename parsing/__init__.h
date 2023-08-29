
#ifndef __INIT___H
# define __INIT___H
# define TRUE 1
# define FALSE 0
# define RED 0
# define GREEN 1
# define BLUE 2
# define X 0
# define Y 1
# define Z 2
# define WIDTH_IDX 1
# define WIDTH_RATIO 2
# define HEIGHT_RATIO 3

# include"../structure.h"
# include"../utils/utils.h"
# include"../setting/view.h"
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<math.h>

typedef struct s_image
{
	double	image_width;
	double	image_height;
	double	aspect_ratio;
}	t_image;

typedef struct s_coordinate_system
{
	t_vector	origin;
	t_vector	horizontal;
	t_vector	vertical;
}	t_co;

typedef struct s_view
{
	double		viewport_height;
	double		viewport_width;
	double		focal_length;
	t_vector	left_bottom;
}	t_view;

typedef struct s_data
{
	t_image		image;
	t_co		co;
	t_view		view;
}	t_data;

int		ft_atoi(const char *str);
#endif
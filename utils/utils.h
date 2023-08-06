#ifndef  UTILS_H
# define UTILS_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

#define PI 3.1415926535897932385;

typedef struct s_vector t_vector;

typedef struct s_color{
    double r;
    double g;
    double b;
} t_color;

typedef struct s_vector{
    double  x;
    double  y;
    double  z;
}   t_vector;

t_vector    new_vector(double x, double y, double z);
void        set_vector(t_vector *vector, double x, double y, double z);
double      inner_product(t_vector vector1, t_vector vector2);
double      len(t_vector vector);
t_vector    unit(t_vector vector);
t_vector    plus_vector(t_vector vector1, t_vector vector2);
t_vector    plus_vector2(t_vector vector1, double x, double y, double z);
t_vector    minus_vector(t_vector vector1, t_vector vector2);
t_vector    minus_vector2(t_vector vector1, double x, double y, double z);
t_vector    scalar_multiply(t_vector vector1, double t);
t_vector    cross_product(t_vector vector1, t_vector vector2);
void        print_vector(t_vector vector);

t_color     new_color(double r, double g, double b);
t_color     plus_color(t_color color1, t_color color2);
t_color     multiply_color(t_color color, double t);

double degrees_to_radians(double degree);


#endif
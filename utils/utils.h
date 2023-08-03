#ifndef  UTILS_H
# define UTILS_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>


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
void    set_vector(t_vector *vector, double x, double y, double z);
double    inner_product(t_vector vector1, t_vector vector2);
double  len(t_vector vector);
t_vector unit(t_vector vector);
t_vector    plus_vector(t_vector vector1, t_vector vector2);
t_vector    plus_vector2(t_vector vector1, double x, double y, double z);
t_vector    minus_vector(t_vector vector1, t_vector vector2);
t_vector    minus_vector2(t_vector vector1, double x, double y, double z);
t_vector    scalar_multiply(t_vector vector1, double t);
t_vector    cross_product(t_vector vector1, t_vector vector2);

t_color new_color(double r, double g, double b);


#endif
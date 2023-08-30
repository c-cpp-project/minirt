#include "utils.h"

t_vector	new_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

void	set_vector(t_vector *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

double	inner_product(t_vector vector1, t_vector vector2)
{
	return (vector1.x * vector2.x
		+vector1.y * vector2.y + vector1.z * vector2.z);
}

double	len(t_vector vector)
{
	return (sqrt(inner_product(vector, vector)));
}

t_vector	unit(t_vector vector)
{
	double	length;

	length = len(vector);
	// if (length == 0)
	// {
	// 	printf("Error\n:Devider is 0");
	// 	exit(0);
	// }
	if (length == 0)
		return (vector);
	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return (vector);
}

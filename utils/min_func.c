#include "utils.h"

double	min_2(double num1, double num2)
{
	if (num1 <= num2)
		return (num1);
	return (num2);
}

double	positive_min_2(double num1, double num2)
{
	if (num1 < 0)
		return (num2);
	if (num2 < 0)
		return (num1);
	return (min_2(num1, num2));
}

t_color	color_min(t_color target, t_color compared)
{
	return (new_color(min_2(target.r, compared.r), min_2(target.g, compared.g),
			min_2(target.b, compared.b)));
}

#include "utils.h"
//0~1 random return
static double random_double_0_1()
{
	return ((double)rand()) / ((double)RAND_MAX + 1.0);
}

double random_double(double min_val, double max_val)
{
	return min_val + (max_val - min_val) * random_double_0_1();
}
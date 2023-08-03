#include "utils.h"

t_vector    cross_product(t_vector vector1, t_vector vector2) {
    t_vector vector;

    vector.x = vector1.y * vector2.z - vector1.z * vector2.x;
    vector.y = vector1.z * vector2.x - vector1.x * vector2.z;
    vector.z = vector1.x * vector2.y - vector1.y * vector2.x;
    return vector;
}
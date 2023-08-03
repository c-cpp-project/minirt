#include "utils.h"

t_vector    plus_vector(t_vector vector1, t_vector vector2) {
    vector1.x += vector2.x;
    vector1.y += vector2.y;
    vector1.z += vector2.z;
    return (vector1);
}

t_vector    plus_vector2(t_vector vector1, double x, double y, double z) {
    vector1.x += x;
    vector1.y += y;
    vector1.z += z;
    return (vector1);
}

t_vector    minus_vector(t_vector vector1, t_vector vector2) {
    vector1.x -= vector2.x;
    vector1.y -= vector2.y;
    vector1.z -= vector2.z;
    return (vector1);
}

t_vector    minus_vector2(t_vector vector1, double x, double y, double z) {
    vector1.x -= x;
    vector1.y -= y;
    vector1.z -= z;
    return (vector1);
}

t_vector    scalar_multiply(t_vector vector1, double t) {
    vector1.x *= t;
    vector1.y *= t;
    vector1.z *= t;
    return vector1;
}
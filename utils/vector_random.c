#include "utils.h"

t_vector random_vector(double min_val, double max_val) {
    return new_vector(random_double(min_val, max_val), random_double(min_val, max_val),
        random_double(min_val, max_val));
}

t_vector random_less_than_one() {
    t_vector candidate;
    while (1) {
        candidate = random_vector(-1, 1);
        if (inner_product(candidate, candidate) < 1) {
            return candidate;
        }
    }
    printf("logic of this function is wrong");
    exit(1);
}

t_vector random_unit_vector() {
    return unit(random_less_than_one());
}

// t_vector random_vector_from_surface() {
// 	t_vector result_vector = random_unit_vector();
// 	if () {

//     }
// }

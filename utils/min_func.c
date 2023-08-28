#include "utils.h"

double  min_2(double num1, double num2) {
    if (num1 <= num2)
        return (num1);
    return (num2);
}

double positive_min_2(double num1, double num2) {
    if (num1 < 0)
        return (num2);
    if (num2 < 0)
        return (num1);
    return min_2(num1, num2);
}


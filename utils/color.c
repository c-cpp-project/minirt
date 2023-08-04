#include "utils.h"

t_color new_color(double r, double g, double b) {
    t_color color;

    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}

t_color    plus_color(t_color color1, t_color color2) {
    color1.r += color2.r;
    color1.g += color2.g;
    color1.b += color2.b;
    return (color1);
}

t_color multiply_color(t_color color, double t) {
    color.r *= t;
    color.g *= t;
    color.b *= t;
    return (color);
}
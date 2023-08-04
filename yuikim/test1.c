#include "../setting/view.h"

t_color ray_color(t_ray ray)
{
	//선언부
	double t;
	t_sphere sp;
	sp.center = new_vector(0, 0, -1);
	sp.radius = 0.5;
	t = hit_sphere(sp, ray);
	if (t > 0.0) {
		printf("%f", t);
		t_vector vector_n = unit(minus_vector(ray_at(&ray, t), new_vector(0, 0, -1)));
		return multiply_color(new_color(vector_n.x + 1, vector_n.y + 1, vector_n.z + 1), 0.5);
	}
	//default 배경
	t_vector direction = ray.dv;
	t = 0.5 * (direction.y + 1.0);
	return plus_color(multiply_color(new_color(1.0, 1.0, 1.0), 1.0  - t), multiply_color(new_color(0.0, 0.0, 0.0), t));
}

void write_color(t_color color) {
	printf("%d %d %d\n", (int)(255.999 * color.r), (int)(255.999 * color.g), (int)(255.999 * color.b));
}

int main()
{
	double aspect_ratio = 16.0 / 9.0;
	int	image_width = 400;
	int	image_height = (int) image_width / aspect_ratio;

	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	t_vector origin = new_vector(0, 0, 0);
	t_vector horizontal = new_vector(viewport_width, 0, 0);
	t_vector vertical = new_vector(0, viewport_height, 0);
	t_vector left_bottom = getleft_bottom(origin, horizontal, vertical, new_vector(0, 0, focal_length));

	printf("P3\n%d %d\n255\n", image_width, image_height);
	int j, i;
	double u, v;
    j = image_height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < image_width)
        {
            u = (double)i / (image_width - 1);
            v = (double)j / (image_height - 1);
			t_ray r = get_ray(scalar_multiply(horizontal, u), scalar_multiply(vertical, v), origin, left_bottom);
            // printf("%d %d %d\n", (int)(255.999 * r), (int)(255.999 * g), (int)(255.999 * b));
			// print_vector(scalar_multiply(horizontal, v));
			t_color color = ray_color(r);
			write_color(ray_color(r));
            ++i;
        }
        --j;
    }

}
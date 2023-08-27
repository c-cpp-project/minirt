#include "../setting/view.h"

t_color ray_color(t_ray ray, t_scene scene, t_count count)
{
	
    // t_hit_record record = hit_cylinder(scene.cl[1], ray);
    // printf("cy : %f %f\n",scene.cl[0].radius, scene.cl[0].height);
    // print_vector(scene.cl[0].center);
    // print_vector(scene.cl[0].bottom);
    // print_vector(scene.cl[0].top);
    // print_vector(scene.cl[0].dv);
    // print_vector(ray.dv);
    // print_vector(ray.origin);
    
	t_hit_record record = hit_world(scene, count, ray, 0, INF);
    // printf("test : %d\n", count.cylinder);
	double t = record.t;
	if (t > 0.0) {
		// printf("test: %f\n", t);
		t_vector vector_n = unit(minus_vector(ray_at(&ray, t), scene.cl[0].center));
		return multiply_color(new_color(vector_n.x + 1, vector_n.y + 1, vector_n.z + 1), 0.5);
	}


	// default 배경
	t_vector direction = ray.dv;
	t = 0.5 * (direction.y + 1.0);
	return plus_color(multiply_color(new_color(1.0, 1.0, 1.0), 1.0  - t), multiply_color(new_color(0.0, 0.0, 0.0), t));
}

void write_color(t_color color) {
	printf("%d %d %d\n", (int)(255.999 * color.r), (int)(255.999 * color.g), (int)(255.999 * color.b));
}

int main() {
    t_scene scene;
    t_count counts;
    scene.cl = malloc(sizeof(t_cylinder) * 3);
    scene.pl = NULL;
    scene.sp = NULL;
    counts.sphere = 2;
    counts.cylinder = 3;
    counts.plane = 0;
    scene.cl = malloc(sizeof(t_cylinder) * counts.cylinder);
    scene.sp = malloc(sizeof(t_sphere) * counts.sphere);

    for (int i = 0 ; i < counts.cylinder; i++) {
        scene.cl[i].center = new_vector(0, 0 - 1.0 * (double) i, -2);
        scene.cl[i].radius = 0.3;
        scene.cl[i].height = 1.0;
        scene.cl[i].dv = unit(new_vector(1, 1.1, 0));
        add_top_and_bottom_vector(&scene.cl[i]);
    }

    for (int i = 0; i < counts.sphere; i++) {
        scene.sp[i].center = new_vector(- 1.0 * (double) i, 0, -2);
        scene.sp[i].radius = 0.2;
    }


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
			t_color color = ray_color(r, scene, counts);
			write_color(color);
            ++i;
        }
        --j;
    }


    // hit_world(scene, count, ray, 0.01, (double)INF);
    // printf("%ld", INF);
}
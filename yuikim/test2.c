#include "../setting/view.h"

t_color ray_color(t_ray ray, t_scene scene, t_count count)
{
	
    // t_hit_record record = hit_cylinder(scene.cl[1], ray);
	t_hit_record record = hit_world(scene, count, ray, 0, INF);
    // printf("test : %d\n", count.cylinder);
	double t = record.t;
	if (t > 0.0) {
		// printf("test: %f\n", t);        
		t_vector vector_n = unit(minus_vector(ray_at(&ray, t), scene.cl[0].center));
        t_vector direction = random_vector_from_surface(record.normal);
		//return multiply_color(new_color(vector_n.x + 1, vector_n.y + 1, vector_n.z + 1), 0.5);
        return phong_ligthing(scene, count, record, ray);
        return multiply_color(new_color(record.normal.x * 0.5 + 1, record.normal.y * 0.5 + 1, record.normal.z * 0.5 + 1), 0.5);
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
    scene.pl = NULL;
    scene.sp = NULL;
    counts.sphere = 2;
    counts.cylinder = 3;
    counts.plane = 1;
    counts.light = 1;
    counts.ambient = 1;
    scene.cl = malloc(sizeof(t_cylinder) * counts.cylinder);
    scene.sp = malloc(sizeof(t_sphere) * counts.sphere);
    scene.pl = malloc(sizeof(t_plane) * counts.plane);
    scene.a = malloc(sizeof(t_ambient) * counts.ambient);
    scene.l = malloc(sizeof(t_light) * counts.light);
    

    for (int i = 0 ; i < counts.cylinder; i++) {
        scene.cl[i].center = new_vector(0, 0 - 1.0 * (double) i, -2);
        scene.cl[i].radius = 0.3;
        scene.cl[i].height = 1.0;
        scene.cl[i].dv = unit(new_vector(1, -1.1, 0));
        scene.cl[i].color = new_color(1.0, 0.0, 0.0);
        // printf("check!");
        // print_color(scene.cl[i].color);
        add_top_and_bottom_vector(&scene.cl[i]);
    }

    for (int i = 0; i < counts.sphere; i++) {
        scene.sp[i].center = new_vector(- 1.0 * (double) i, 0, -2);
        scene.sp[i].color = new_color(0.0, 1.0, 0.0);
        scene.sp[i].radius = 0.5 - 0.2 * i;
    }

    for (int i = 0; i < counts.plane; i++) {
        scene.pl[i].dv = new_vector(0 ,1, 0);
        scene.pl[i].point = new_vector(0, -1, -2);
        scene.pl[i].color = new_color(0.5, 1.0, 1.0);
    }

    for (int i = 0; i < counts.light; i++) {
        scene.l[i].position = new_vector(0.1 + (0.1) * i, 6.0, 0);
        scene.l[i].color = new_color(1, 1, 1);
        scene.l[i].ratio = 0.6;
        scene.l[i].color = multiply_color(scene.l[i].color, scene.l[i].ratio);
    }

    for (int i = 0; i < counts.ambient; i++) {
        scene.a[i].color = new_color(1, 1, 1);
        scene.a[i].ratio = 0.05;
        scene.a[i].color = multiply_color(scene.a[i].color, scene.a[i].ratio);
        
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
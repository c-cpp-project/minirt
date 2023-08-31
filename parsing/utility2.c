
#include"parsing.h"

void	free_scene(t_scene *scene)
{
	free(scene->a);
	free(scene->c);
	free(scene->cl);
	free(scene->l);
	free(scene->pl);
	free(scene->sp);
	free(scene);
}

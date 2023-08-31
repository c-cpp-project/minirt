

#include"parsing.h"

void	parameter_init(t_count *element)
{
	element->ambient = 0;
	element->camera = 0;
	element->light = 0;
	element->plane = 0;
	element->cylinder = 0;
}

void	parameter_format(char **line, char *mode)
{
	int		length;

	length = 0;
	while (line[length])
		length++;
	if (*mode == 'A' && length != 3)
		put_error("paramater_format A");
	else if (*mode == 'C' && length != 4)
		put_error("paramater_format C");
	else if (*mode == 'L' && length != 4)
		put_error("paramater_format L");
	else if (ft_strncmp(mode, "pl", 2) == 0 && length != 4)
		put_error("paramater_format pl");
	else if (ft_strncmp(mode, "sp", 2) == 0 && length != 4)
		put_error("paramater_format sp");
	else if (ft_strncmp(mode, "cy", 2) == 0 && length != 6)
		put_error("paramater_format cy");
}

void	parameter_count(char *buffer, t_count *element)
{
	if (ft_strncmp(buffer, "A", 1) == 0 && ft_strlen(buffer) == 1)
		element->ambient++;
	else if (ft_strncmp(buffer, "C", 1) == 0 && ft_strlen(buffer) == 1)
		element->camera++;
	else if (ft_strncmp(buffer, "L", 1) == 0 && ft_strlen(buffer) == 1)
		element->light++;
	else if (ft_strncmp(buffer, "pl", 2) == 0 && ft_strlen(buffer) == 2)
		element->plane++;
	else if (ft_strncmp(buffer, "sp", 2) == 0 && ft_strlen(buffer) == 2)
		element->sphere++;
	else if (ft_strncmp(buffer, "cy", 2) == 0 && ft_strlen(buffer) == 2)
		element->cylinder++;
	else
		put_error("paramater_count wrong mode");
}

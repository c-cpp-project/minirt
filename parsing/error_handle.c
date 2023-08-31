
#include"parsing.h"

void	put_error(char *msg)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, msg, ft_strlen(msg));
	exit(1);
}
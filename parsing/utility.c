/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:07:43 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/06 15:37:06 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

char	*ft_strdup(char *dest, size_t length)
{
	char	*src;
	int		i;

	src = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (dest[i])
	{
		src[i] = dest[i];
		i++;
	}
	src[i] = 0;
	free(dest);
	return (src);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	length_dest;
	size_t	length_src;

	i = 0;
	j = 0;
	length_dest = ft_strlen(dest);
	length_src = ft_strlen(src);
	if (size <= length_dest)
		return (size + length_src);
	while (dest[i])
		i++;
	while (src[j] && j < size - length_dest - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (length_dest + length_src);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while ((s1[i] || s2[i]) && ret == 0 && i < n)
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (ret);
}

t_color	get_color(char *buffer)
{
	char	**line;
	double	nbr[3];
	int		i;

	line = ft_split(buffer, ',');
	i = 0;
	while (line[i])
	{
		nbr[i] = ft_atol(line[i]);
		i++;
	}
	free_split(line);
	return (new_color(nbr[RED] * 1.0, nbr[GREEN] * 1.0, nbr[BLUE] * 1.0));
}

t_vector	get_vector(char *buffer)
{
	char	**line;
	double	nbr[3];
	int		i;

	line = ft_split(buffer, ',');
	i = 0;
	while (line[i])
	{
		nbr[i] = ft_atol(line[i]);
		// printf("%lf, ", nbr[i]);
		i++;
	}
	// printf("\n");
	free_split(line);
	return (new_vector(nbr[X] * 1.0, nbr[Y] * 1.0, nbr[Z] * 1.0));
}

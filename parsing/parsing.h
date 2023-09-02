/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:39:02 by yuikim            #+#    #+#             */
/*   Updated: 2023/09/02 14:30:41 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define BUFFER_SIZE 32
# define TRUE 1
# define FALSE 0
# define RED 0
# define GREEN 1
# define BLUE 2
# define X 0
# define Y 1
# define Z 2

# include"../structure.h"
# include"../utils/utils.h"
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<math.h>

typedef struct s_element_count
{
	int	ambient;
	int	camera;
	int	light;
	int	sphere;
	int	plane;
	int	cylinder;
}	t_count;

// utility.c
char		*ft_strdup(char *dest, size_t length);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
t_color		get_color(char *buffer);
t_vector	get_vector(char *buffer, int is_normalize);

// utility2.c
void		free_scene(t_scene *scene);

// parsing.c
char		*write_buffer(int fd);
t_scene		*parsing(const char *path, t_count *element);
void		put_error(char *msg);
t_scene		*tokenizer(char **buffer, t_count *element);
t_scene		*assign_scene(char *src, t_count *element);

// format_check.c
void		parameter_init(t_count *element);
void		parameter_format(char **line, char *mode);
void		parameter_count(char *buffer, t_count *element);
void		each_is(t_count *element);

// ft_split.c
size_t		mk_branch(const char *str, char c);
char		*mk_leaf(const char *str, size_t len);
size_t		mk_tree(char const *s, char c, size_t size, char **branch);
char		**ft_split(char const *s, char c);
void		free_split(char **buffer);

// ft_split_group.c
int			exclude_whitespace(char *str, int is_whitespace, int s_idx);
size_t		mk_branch_group(char *str, int is_white);
char		*mk_leaf_group(char *str, size_t len);
size_t		mk_tree_group(char *str, int flag, size_t size, char **branch);
char		**ft_split_group(char *s, int is_whitespace);

// ft_math.c
double		ft_atol(const char *str);
double		ft_decimal_part(const char *str);
size_t		ft_strlen(const char *str);

// extract.c
t_ambient	*extract_ambient(char **buffer, t_count *element);
t_camera	*extract_camera(char **buffer, t_count *element);
t_light		*extract_light(char **buffer, t_count *element);
t_sphere	*extract_sphere(char **buffer, t_count *element);
t_plane		*extract_plane(char **buffer, t_count *element);

// extract2.c
t_cylinder	*extract_cylinder(char **buffer, t_count *element);
void		add_top_and_bottom_vector(t_cylinder *cylinder);
#endif
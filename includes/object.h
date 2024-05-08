/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:21:49 by bwisniew          #+#    #+#             */
/*   Updated: 2024/05/08 17:36:51 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>

# include "color.h"
# include "vec.h"

# define TYPE_COUNT 6

# define OBJECT_CAMERA "C"
# define OBJECT_AMBIENT "A"
# define OBJECT_LIGHT "L"
# define OBJECT_PLANE "pl"
# define OBJECT_SPHERE "sp"
# define OBJECT_CYLINDER "cy"

typedef struct s_engine	t_engine;
typedef struct s_ray	t_ray;

typedef enum e_type_index
{
	CAMERA,
	AMBIENT,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type_index;

typedef struct s_obj_type
{
	t_type_index	index;
	char			*name;
	size_t			args_count;
	uint8_t			(*init)(t_engine * engine, char **args);
}	t_obj_type;

typedef struct s_camera
{
	t_vec3		position;
	t_vec3		rotation;
	int32_t		fov;
}				t_camera;

typedef struct t_ambient
{
	t_color	color;
	float	lighting;
}	t_ambient;

typedef struct s_light
{
	float	brightness;
}	t_light;

typedef struct s_sphere
{
	float	diameter;
}	t_sphere;

typedef struct s_cylinder
{
	float	diameter;
	float	height;
}	t_cylinder;

typedef union u_specific
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_light		light;
}	t_specific;

typedef struct s_object
{
	t_obj_type	*type;
	t_vec3		position;
	t_vec3		rotation;
	t_color		color;
	t_specific	specific;
	float		(*get_hit_distance)(struct s_object *self, t_ray ray);
	t_vec3		(*get_normal)(struct s_object *self, t_vec3 hit_pos);
}	t_object;

uint8_t	init_ambient(t_engine *engine, char **args);
uint8_t	init_camera(t_engine *engine, char **args);
uint8_t	init_light(t_engine *engine, char **args);
uint8_t	init_cylinder(t_engine *engine, char **args);
uint8_t	init_plane(t_engine *engine, char **args);
uint8_t	init_sphere(t_engine *engine, char **args);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:29:49 by bwisniew          #+#    #+#             */
/*   Updated: 2024/11/21 16:13:53 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "color.h"
# include <stdbool.h>

typedef struct s_mat4	t_mat4;
typedef struct s_mat3	t_mat3;

typedef union u_vec2
{
	struct
	{
		double	x;
		double	y;
	};
	double	arr[2];
}	t_vec2;

typedef union u_vec3
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	t_vec2	xy;
	double	arr[3];
}	t_vec3;

typedef union u_vec4
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	t_vec3	xyz;
	double	arr[4];
}	t_vec4;

double	vec3_dot(t_vec3 a, t_vec3 b);
double	vec3_dist_sqr(t_vec3 a, t_vec3 b);
t_vec3	vec3_multiply(t_vec3 a, double b);
t_vec3	vec3_divide(t_vec3 a, t_vec3 b);
t_vec3	vec3_multiply_vec(t_vec3 a, t_vec3 b);
t_vec3	vec3_product(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_substract(t_vec3 a, t_vec3 b);
t_vec3	vec3_normalize(t_vec3 a);
t_vec3	vec3_reflect(t_vec3 incident, t_vec3 normal);
t_vec3	vec3_refract(t_vec3 ray_dir, t_vec3 normal, double refract);
t_vec3	color_to_vec3(t_color color);
t_vec4	mat4vec4_product(t_vec4 vec, t_mat4 mat);
t_vec3	mat3vec3_product(t_vec3 vec, t_mat3 mat);
t_color	vec3_to_color(t_vec3 vec);
t_vec3	vec3_cap(t_vec3 vec, double min, double max);

#endif

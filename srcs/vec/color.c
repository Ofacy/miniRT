/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:43:33 by lcottet           #+#    #+#             */
/*   Updated: 2024/05/08 22:55:22 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "vec.h"

t_color	vec3_to_color(t_vec3 vec)
{
	t_color	color = (t_color){0xFFFFFFFF};
	if (vec.x <= 1)
		color.r = (uint8_t)(vec.x * 255.0f);
	if (vec.y <= 1)
		color.g = (uint8_t)(vec.y * 255.0f);
	if (vec.z <= 1)
		color.b = (uint8_t)(vec.z * 255.0f);
	return (color);
}

t_vec3	color_to_vec3(t_color color)
{
	return ((t_vec3){{
		(float) color.r / 255.0f,
		(float) color.g / 255.0f,
		(float) color.b / 255.0f
	}});
}
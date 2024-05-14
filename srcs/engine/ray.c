/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:10:01 by lcottet           #+#    #+#             */
/*   Updated: 2024/05/12 08:44:52 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_hit_payload	hit(t_hit_payload payload, t_ray ray)
{
	t_vec3	origin;

	origin = vec3_substract(ray.origin, payload.object->position);
	payload.world_position = vec3_add(origin,
			vec3_multiply(ray.direction, payload.hit_distance));
	if (payload.object->get_normal != NULL)
		payload.world_normal = payload.object->get_normal(payload.object,
				ray, payload);
	payload.world_position = vec3_add(payload.world_position,
			payload.object->position);
	return (payload);
}

static t_hit_payload	miss(t_hit_payload payload)
{
	payload.hit_distance = -1;
	return (payload);
}

t_hit_payload	trace_ray(t_engine *engine, t_ray ray)
{
	t_hit_payload	payload;
	t_hit_payload	snapshot;
	size_t			i;
	float			current_dist;
	t_object		*obj;

	payload.hit_distance = FLT_MAX;
	payload.object = NULL;
	i = 0;
	while (i < engine->objects.len)
	{
		obj = ((t_object *)engine->objects.tab) + i;
		snapshot = payload;
		current_dist = obj->get_hit_distance(obj, ray, &snapshot);
		if (current_dist < payload.hit_distance && current_dist > 0.0f)
		{
			payload = snapshot;
			payload.object = obj;
			payload.hit_distance = current_dist;
		}
		i++;
	}
	if (payload.object == NULL)
		return (miss(payload));
	return (hit(payload, ray));
}

t_ray	init_ray(t_engine *engine, t_vec2 pos)
{
	t_ray	ray;
	t_vec4	target;
	t_vec3	ray_dir_norm;
	t_vec4	ray_dir_tmp;

	pos.x = (pos.x / WIDTH) * 2.0f -1.0f;
	pos.y = (pos.y / HEIGHT) * 2.0f -1.0f;
	target = mat4vec4_product((t_vec4){{
			pos.x, pos.y, 1, 1
		}}, mat4_inverse(engine->camera.projection));
	ray_dir_norm = vec3_normalize(vec3_multiply((t_vec3)
			{{target.x, target.y, target.z}}, 1 / target.w));
	ray_dir_tmp = mat4vec4_product((t_vec4){{
			ray_dir_norm.x, ray_dir_norm.y, ray_dir_norm.z, 0.0f
		}}, mat4_inverse(engine->camera.view));
	ray.direction = (t_vec3)
	{{
		ray_dir_tmp.x, ray_dir_tmp.y, ray_dir_tmp.z
	}};
	ray.origin = engine->camera.position;
	ray.direction = vec3_normalize(ray.direction);
	return (ray);
}
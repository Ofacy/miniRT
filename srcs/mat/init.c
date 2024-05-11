/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:04:28 by bwisniew          #+#    #+#             */
/*   Updated: 2024/05/11 05:35:42 by bwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "libft.h"

t_mat4	mat4_init(float a)
{
	return ((t_mat4){{
			a, a, a, a,
			a, a, a, a,
			a, a, a, a,
			a, a, a, a
		}});
}

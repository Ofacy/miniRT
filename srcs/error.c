/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:48:29 by bwisniew          #+#    #+#             */
/*   Updated: 2024/05/09 18:12:07 by lcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "engine.h"

uint8_t	err(char *err)
{
	printf("Error\n%s: %s\n", err, strerror(errno));
	return (FAILURE);
}

uint8_t	custom_error(char *err, char *msg)
{
	printf("Error\n%s: %s\n", err, msg);
	return (FAILURE);
}

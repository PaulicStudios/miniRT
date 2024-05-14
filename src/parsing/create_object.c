/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:58:00 by lgreau            #+#    #+#             */
/*   Updated: 2024/05/14 17:56:31 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief Initialize an ambient light using the args as values
 *
 * @param type
 * @param args
 * @return int : -1 if error else 0
 */
int	create_ambient_light(t_scene_object *obj, char **args)
{
	obj->type = AMBIENT_LIGHT;
	obj->s_ambient_light.intensity = ft_atod(args[1]);
	printf("intensity = %f\n", obj->s_ambient_light.intensity);
	if (obj->s_ambient_light.intensity < 0
		|| obj->s_ambient_light.intensity > 1)
		return (set_error((char *)__func__, INVALID_ARG), -1);
	obj->s_ambient_light.color = atoc(args[2]);
	return ((*get_errno() == NO_ERROR) - 1);
}

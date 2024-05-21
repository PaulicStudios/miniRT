/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_spot_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgreau <lgreau@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:43:27 by lgreau            #+#    #+#             */
/*   Updated: 2024/05/21 14:53:34 by lgreau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief Initialize a spot light using the args as values
 *
 * @param type
 * @param args
 * @return int : -1 if error else 0
 */
int	create_spot_light(t_scene_object *obj, char **args)
{
	if (!args[1] || !args[2] || !args[3] || args[4])
		return (set_error((char *)__func__, INVALID_ARG), -1);
	obj->type = SPOT_LIGHT;
	obj->s_spot_light.pos = atov(args[1]);
	if (!obj->s_spot_light.pos)
		return (-1);
	obj->s_spot_light.intensity = ft_atod(args[2]);
	if (obj->s_spot_light.intensity < 0
		|| obj->s_spot_light.intensity > 1)
		return (free(obj->s_spot_light.pos),
			set_error((char *)__func__, INVALID_ARG), -1);
	obj->s_spot_light.color = atoc(args[3]);
	return (0);
}

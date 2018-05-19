/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:08 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/18 05:28:40 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_light(t_rtv1 *rtv1)
{
	t_light				*light;
	t_light				*tmp;

	light = rtv1->light;
	if (!light)
		return ;
	while (light)
	{
		tmp = light->next;
		free(light->pos);
		free(light->light_color);
		free(light);
		light = tmp;
	}
	rtv1->light = NULL;
}

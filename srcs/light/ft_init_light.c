/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:24 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/30 06:57:40 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_init_light(t_rtv1 *rtv1, void *obj)
{
	t_light			*light;

	if (ft_size_darray(rtv1->var->data) != 2)
		ft_print_error("Error in light number parameters", TRUE);
	light = (t_light*)obj;
	light->pos = ft_create_vector(rtv1->var->data[0]);
	light->light_color = ft_create_color(rtv1->var->data[1]);
}

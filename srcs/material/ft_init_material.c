/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:01 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 16:54:56 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_init_material(t_rtv1 *rtv1, void *obj)
{
	t_material		*material;

	if (ft_size_darray(rtv1->var->data) != 2)
		ft_print_error("Error in material number parameters", TRUE);
	material = (t_material*)obj;
	material->material_color = ft_create_color(rtv1->var->data[0]);
	if (ft_isdigitpoint(rtv1->var->data[1]) || rtv1->var->data[1][0] == '\0')
		ft_print_error("Error: material shiness must be a valid number", TRUE);
	material->shiness = ft_atof(rtv1->var->data[1]);
}

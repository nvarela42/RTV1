/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:39:07 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:50:06 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_init_cylinder(t_rtv1 *rtv1, void *obj)
{
	t_cylinder			*cylinder;
	t_vector			*tmp;

	if (ft_size_darray(rtv1->var->data) != 5)
		ft_print_error("Error in cylinder number parameters", TRUE);
	cylinder = (t_cylinder*)obj;
	cylinder->pos = ft_create_vector(rtv1->var->data[0]);
	cylinder->rotation = ft_create_vector(rtv1->var->data[1]);
	cylinder->translation = ft_create_vector(rtv1->var->data[2]);
	if (ft_isdigitpoint(rtv1->var->data[3]) || rtv1->var->data[3][0] == '\0')
		ft_print_error("Error: radius must be a valid number", TRUE);
	cylinder->radius = ft_atof(rtv1->var->data[3]);
	if (ft_isalldigit(rtv1->var->data[4]) || rtv1->var->data[4][0] == '\0')
		ft_print_error("Error: material id must be a number", TRUE);
	cylinder->material_id = ft_atoi(rtv1->var->data[4]);
	tmp = ft_plus_vector(cylinder->pos, cylinder->translation);
	free(cylinder->pos);
	cylinder->pos = tmp;
	rtv1->nb_object++;
}

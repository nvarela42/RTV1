/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:31:06 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 19:58:57 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_init_sphere(t_rtv1 *rtv1, void *obj)
{
	t_sphere		*sphere;
	t_vector		*tmp;

	if (ft_size_darray(rtv1->var->data) != 5)
		ft_print_error("Error in sphere number parameters", TRUE);
	sphere = (t_sphere*)obj;
	tmp = ft_create_vector(rtv1->var->data[0]);
	if (ft_isdigitpoint(rtv1->var->data[1]) || rtv1->var->data[1][0] == '\0')
		ft_print_error("Error: radius must be a valid number", TRUE);
	sphere->radius = ft_atof(rtv1->var->data[1]);
	sphere->rotation = ft_create_vector(rtv1->var->data[2]);
	sphere->translation = ft_create_vector(rtv1->var->data[3]);
	if (ft_isalldigit(rtv1->var->data[4]) || rtv1->var->data[4][0] == '\0')
		ft_print_error("Error: material id must be a number", TRUE);
	sphere->material_id = ft_atoi(rtv1->var->data[4]);
	sphere->pos = ft_plus_vector(tmp, sphere->translation);
	free(tmp);
	rtv1->nb_object++;
}

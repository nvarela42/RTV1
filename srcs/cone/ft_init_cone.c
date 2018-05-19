/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:05:22 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/30 07:00:29 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_init_cone(t_rtv1 *rtv1, void *obj)
{
	t_cone			*cone;
	t_vector		*tmp;

	if (ft_size_darray(rtv1->var->data) != 5)
		ft_print_error("Error in cone number parameters", TRUE);
	cone = (t_cone*)obj;
	cone->pos = ft_create_vector(rtv1->var->data[0]);
	cone->rotation = ft_create_vector(rtv1->var->data[1]);
	cone->translation = ft_create_vector(rtv1->var->data[2]);
	if (ft_isdigitpoint(rtv1->var->data[3]) || rtv1->var->data[3][0] == '\0')
		ft_print_error("Error: radius must be a valid number", TRUE);
	cone->radius = ft_atof(rtv1->var->data[3]);
	if (ft_isalldigit(rtv1->var->data[4]) || rtv1->var->data[4][0] == '\0')
		ft_print_error("Error: material id must be a number", TRUE);
	cone->material_id = ft_atoi(rtv1->var->data[4]);
	tmp = ft_plus_vector(cone->pos, cone->translation);
	free(cone->pos);
	cone->pos = tmp;
	rtv1->nb_object++;
}

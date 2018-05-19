/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:45 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/30 07:11:10 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_init_plane(t_rtv1 *rtv1, void *obj)
{
	t_plane			*plane;
	t_vector		*tmp;

	if (ft_size_darray(rtv1->var->data) != 4)
		ft_print_error("Error in plane number parameters", TRUE);
	plane = (t_plane*)obj;
	tmp = ft_create_vector(rtv1->var->data[0]);
	plane->normale = ft_create_vector(rtv1->var->data[1]);
	ft_vector_normalize(plane->normale);
	plane->translation = ft_create_vector(rtv1->var->data[2]);
	if (ft_isalldigit(rtv1->var->data[3]) || rtv1->var->data[3][0] == '\0')
		ft_print_error("Error: material id must be a number", TRUE);
	plane->material_id = ft_atoi(rtv1->var->data[3]);
	plane->pos = ft_plus_vector(tmp, plane->translation);
	free(tmp);
	rtv1->nb_object++;
}

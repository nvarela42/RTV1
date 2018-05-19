/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_material_object.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:11 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 16:56:36 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			ft_link_mat_cone(t_material *mat, t_cone *cone)
{
	if (!cone)
		return ;
	while (cone)
	{
		cone->material = ft_get_material(mat, cone->material_id);
		if (cone->material == NULL)
			ft_print_error("Unknow material (cone).", TRUE);
		cone = cone->next;
	}
}

static void			ft_link_mat_cylinder(t_material *mat, t_cylinder *cylinder)
{
	if (!cylinder)
		return ;
	while (cylinder)
	{
		cylinder->material = ft_get_material(mat, cylinder->material_id);
		if (cylinder->material == NULL)
			ft_print_error("Unknow material (cylinder).", TRUE);
		cylinder = cylinder->next;
	}
}

static void			ft_link_mat_plane(t_material *mat, t_plane *plane)
{
	if (!plane)
		return ;
	while (plane)
	{
		plane->material = ft_get_material(mat, plane->material_id);
		if (plane->material == NULL)
			ft_print_error("Unknow material (plane).", TRUE);
		plane = plane->next;
	}
}

static void			ft_link_mat_sphere(t_material *mat, t_sphere *sphere)
{
	if (!sphere)
		return ;
	while (sphere)
	{
		sphere->material = ft_get_material(mat, sphere->material_id);
		if (sphere->material == NULL)
			ft_print_error("Unknow material (sphere).", TRUE);
		sphere = sphere->next;
	}
}

void				ft_link_material_object(t_rtv1 *rtv1)
{
	ft_link_mat_sphere(rtv1->material, rtv1->sphere);
	ft_link_mat_plane(rtv1->material, rtv1->plane);
	ft_link_mat_cylinder(rtv1->material, rtv1->cylinder);
	ft_link_mat_cone(rtv1->material, rtv1->cone);
}

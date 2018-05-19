/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_plane_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:35:13 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/26 10:15:18 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_search_plane_hit(t_rtv1 *rtv1, t_plane *plane, t_ray *ray)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vect_tmp;

	if (!plane)
		return ;
	while (plane)
	{
		if (ft_calc_discri_plane(plane, ray, &obj_tmp))
		{
			vect_tmp = ft_moins_vector(&obj_tmp.inter, &ray->start_pos);
			dist_tmp = ft_vector_square_len(vect_tmp);
			free(vect_tmp);
			vect_tmp = NULL;
			if (dist_tmp < ray->dist)
			{
				ray->dist = dist_tmp;
				ft_copy_hit(rtv1, obj_tmp);
			}
		}
		plane = plane->next;
	}
}

void	ft_lum_hit_plane(t_rtv1 *rtv1, t_plane *plane, t_ray *ray, int *blocked)
{
	float			ret_val;
	t_hit			obj_tmp;
	t_vector		*vect_tmp;

	if (!plane)
		return ;
	while (plane)
	{
		if (plane != rtv1->hit.object)
		{
			if (ft_calc_discri_plane(plane, ray, &obj_tmp))
			{
				vect_tmp = ft_moins_vector(&obj_tmp.inter, &ray->start_pos);
				ret_val = ft_vector_square_len(vect_tmp);
				free(vect_tmp);
				vect_tmp = NULL;
				if (ret_val < ray->dist)
					*blocked = 1;
			}
		}
		plane = plane->next;
	}
}

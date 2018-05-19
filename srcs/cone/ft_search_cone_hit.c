/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_cone_hit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:35:19 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:44:49 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_search_cone_hit(t_rtv1 *rtv1, t_cone *cone, t_ray *ray)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vect_tmp;

	if (!cone)
		return ;
	while (cone)
	{
		if (ft_calc_discri_cone(cone, ray, &obj_tmp))
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
		cone = cone->next;
	}
}

void	ft_lum_hit_cone(t_rtv1 *rtv1, t_cone *cone, t_ray *ray, int *blocked)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vect_tmp;

	if (!cone)
		return ;
	while (cone)
	{
		if (cone != rtv1->hit.object)
		{
			if (ft_calc_discri_cone(cone, ray, &obj_tmp))
			{
				vect_tmp = ft_moins_vector(&obj_tmp.inter, &ray->start_pos);
				dist_tmp = ft_vector_magnitude(vect_tmp);
				free(vect_tmp);
				vect_tmp = NULL;
				if (dist_tmp < ray->dist)
					*blocked = 1;
			}
		}
		cone = cone->next;
	}
}

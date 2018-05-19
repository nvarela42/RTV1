/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_cylinder_hit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:02:01 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:50:29 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_search_cylinder_hit(t_rtv1 *rtv1, t_cylinder *cylinder, t_ray *ray)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vect_tmp;

	if (!cylinder)
		return ;
	while (cylinder)
	{
		if (ft_calc_discri_cyl(cylinder, ray, &obj_tmp))
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
		cylinder = cylinder->next;
	}
}

void	ft_lum_hit_cyl(t_rtv1 *rtv1, t_cylinder *cyl, t_ray *ray, int *blocked)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vect_tmp;

	if (!cyl)
		return ;
	while (cyl)
	{
		if (cyl != rtv1->hit.object)
		{
			if (ft_calc_discri_cyl(cyl, ray, &obj_tmp))
			{
				vect_tmp = ft_moins_vector(&obj_tmp.inter, &ray->start_pos);
				dist_tmp = ft_vector_magnitude(vect_tmp);
				free(vect_tmp);
				vect_tmp = NULL;
				if (dist_tmp < ray->dist)
					*blocked = 1;
			}
		}
		cyl = cyl->next;
	}
}

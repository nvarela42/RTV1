/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_sphere_hit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 00:52:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:58:32 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_search_sphere_hit(t_rtv1 *rtv1, t_sphere *sph, t_ray *ray)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vec_tmp;

	if (!sph)
		return ;
	while (sph)
	{
		if (ft_calc_discri_sphere(sph, ray, &obj_tmp))
		{
			vec_tmp = ft_moins_vector(&obj_tmp.inter, &ray->start_pos);
			dist_tmp = ft_vector_square_len(vec_tmp);
			free(vec_tmp);
			vec_tmp = NULL;
			if (dist_tmp < ray->dist)
			{
				ray->dist = dist_tmp;
				ft_copy_hit(rtv1, obj_tmp);
			}
		}
		sph = sph->next;
	}
}

void	ft_lum_hit_sphere(t_rtv1 *rtv1, t_sphere *sph, t_ray *ray, int *block)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		*vec_tmp;

	if (!sph)
		return ;
	while (sph)
	{
		if (sph != rtv1->hit.object)
		{
			if (ft_calc_discri_sphere(sph, ray, &obj_tmp))
			{
				vec_tmp = ft_moins_vector(&obj_tmp.inter, &ray->start_pos);
				dist_tmp = ft_vector_magnitude(vec_tmp);
				free(vec_tmp);
				vec_tmp = NULL;
				if (dist_tmp < ray->dist)
					*block = 1;
			}
		}
		sph = sph->next;
	}
}

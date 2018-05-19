/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_plane.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:13:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:57:19 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_plane_inters(t_tmp_plane *ptmp, float t, t_plane *plane)
{
	t_vector		*tmp;

	tmp = ft_create_vector("0,0,0");
	tmp->x = ptmp->ray->start_pos.x + ptmp->ray->dir.x * t;
	tmp->y = ptmp->ray->start_pos.y + ptmp->ray->dir.y * t;
	tmp->z = ptmp->ray->start_pos.z + ptmp->ray->dir.z * t;
	ptmp->hit->touch = 1;
	ptmp->hit->object = (void*)ptmp->plane;
	ptmp->hit->inter = *tmp;
	if (ptmp->b > 0)
	{
		ptmp->hit->normal.x = -(plane->normale->x);
		ptmp->hit->normal.y = -(plane->normale->y);
		ptmp->hit->normal.z = -(plane->normale->z);
	}
	else
		ptmp->hit->normal = *plane->normale;
	ptmp->hit->material = plane->material;
	free(tmp);
}

static int		ft_calc_plane_inter(t_tmp_plane *ptmp, t_plane *plane)
{
	float			t;

	t = ptmp->delta;
	ft_plane_inters(ptmp, t, plane);
	return (t);
}

int				ft_calc_discri_plane(t_plane *plane, t_ray *ray, t_hit *tmp)
{
	t_tmp_plane		ptmp;
	t_vector		*pos;

	ptmp.b = ft_vector_dot_mult(plane->normale, &ray->dir);
	if (ptmp.b == 0)
		return (0);
	pos = ft_moins_vector(&ray->start_pos, plane->pos);
	ptmp.a = ft_vector_dot_mult(plane->normale, pos);
	free(pos);
	ptmp.delta = -ptmp.a / ptmp.b;
	if (ptmp.delta < 0)
		return (0);
	else
	{
		ptmp.plane = plane;
		ptmp.ray = ray;
		ptmp.hit = tmp;
		return (ft_calc_plane_inter(&ptmp, plane));
	}
}

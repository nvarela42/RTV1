/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_cone.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:21:23 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:49:16 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	ft_rotation_cone(t_cone *cone)
{
	t_vector	ret;

	ret.x = cone->rotation->z;
	ret.y = cone->rotation->y;
	ret.z = cone->rotation->x;
	return (ret);
}

static void		ft_cone_inters(t_tmp_cone *ctmp, float t, t_cone *cone)
{
	t_vector		*tmp;
	t_vector		*tmp2;
	t_vector		*tmp3;

	tmp = ft_create_vector("0,0,0");
	tmp->x = ctmp->ray->start_pos.x + ctmp->ray->dir.x * t;
	tmp->y = ctmp->ray->start_pos.y + ctmp->ray->dir.y * t;
	tmp->z = ctmp->ray->start_pos.z + ctmp->ray->dir.z * t;
	tmp2 = ft_moins_vector(tmp, ctmp->cone->pos);
	tmp3 = ft_div_vector(tmp2, ctmp->cone->radius);
	ctmp->hit->touch = 1;
	ctmp->hit->object = (void*)ctmp->cone;
	ctmp->hit->normal = *tmp3;
	ctmp->hit->inter = *tmp;
	ctmp->hit->material = cone->material;
	free(tmp);
	free(tmp2);
	free(tmp3);
}

static int		ft_calc_cone_intersect(t_tmp_cone *ctmp, t_cone *cone)
{
	float			t1;
	float			t2;
	float			t;

	t1 = (-ctmp->b + sqrt(ctmp->delta)) / (2 * ctmp->a);
	t2 = (-ctmp->b - sqrt(ctmp->delta)) / (2 * ctmp->a);
	if (t1 < 0 || t2 < 0)
		return (0);
	else if (t1 < t2)
		t = t1;
	else
		t = t2;
	ft_cone_inters(ctmp, t, cone);
	return (1);
}

static float	ft_discri(t_ray *ray, t_tmp_cone *ctmp, t_cone *cone)
{
	t_vector	*pos;
	t_vector	ray_dir;
	t_vector	rotation;
	float		rad;

	ray_dir = ray->dir;
	rotation = ft_rotation_cone(cone);
	pos = ft_moins_vector(&ray->start_pos, cone->pos);
	ft_rotation(pos, rotation);
	ft_rotation(&ray_dir, rotation);
	rad = sin(ft_calc_angle(cone->radius)) * sin(ft_calc_angle(cone->radius));
	ctmp->a = ray_dir.x * ray_dir.x - ray_dir.y * ray_dir.y * rad +
	ray_dir.z * ray_dir.z;
	ctmp->b = 2 * (ray_dir.x * pos->x - ray_dir.y * pos->y * rad +
	ray_dir.z * pos->z);
	ctmp->c = pos->x * pos->x - pos->y * rad * pos->y + pos->z * pos->z;
	free(pos);
	return (ctmp->b * ctmp->b - 4 * ctmp->a * ctmp->c);
}

int				ft_calc_discri_cone(t_cone *cone, t_ray *ray, t_hit *tmp)
{
	t_tmp_cone	ctmp;

	ctmp.delta = ft_discri(ray, &ctmp, cone);
	if (ctmp.delta < 0)
		return (0);
	else
	{
		ctmp.cone = cone;
		ctmp.ray = ray;
		ctmp.hit = tmp;
		return (ft_calc_cone_intersect(&ctmp, cone));
	}
}

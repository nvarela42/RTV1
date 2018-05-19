/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:02:19 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 17:00:54 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	ft_rotation_sphere(t_sphere *sphere)
{
	t_vector	ret;

	ret.x = sphere->rotation->x;
	ret.y = sphere->rotation->y;
	ret.z = sphere->rotation->z;
	return (ret);
}

static void		ft_sphere_inter(t_tmp_sphere *stmp, float t, t_sphere *sphere)
{
	t_vector		*tmp;
	t_vector		*tmp2;
	t_vector		*tmp3;

	tmp = ft_create_vector("0,0,0");
	tmp->x = stmp->ray->start_pos.x + stmp->ray->dir.x * t;
	tmp->y = stmp->ray->start_pos.y + stmp->ray->dir.y * t;
	tmp->z = stmp->ray->start_pos.z + stmp->ray->dir.z * t;
	tmp2 = ft_moins_vector(tmp, stmp->sphere->pos);
	tmp3 = ft_div_vector(tmp2, stmp->sphere->radius);
	stmp->hit->touch = 1;
	stmp->hit->object = (void*)stmp->sphere;
	stmp->hit->normal = *tmp3;
	stmp->hit->inter = *tmp;
	stmp->hit->material = sphere->material;
	free(tmp);
	free(tmp2);
	free(tmp3);
}

static int		ft_calc_sphere_inter(t_tmp_sphere *stmp, t_sphere *sphere)
{
	float			t1;
	float			t2;
	float			t;

	t1 = (-stmp->b + sqrt(stmp->delta)) / (2 * stmp->a);
	t2 = (-stmp->b - sqrt(stmp->delta)) / (2 * stmp->a);
	if (t1 < 0 || t2 < 0)
		return (0);
	else if (t1 < t2)
		t = t1;
	else
		t = t2;
	ft_sphere_inter(stmp, t, sphere);
	return (1);
}

static float	ft_discri(t_ray *ray, t_tmp_sphere *stmp, t_sphere *sphere)
{
	t_vector		*pos;
	t_vector		ray_dir;
	t_vector		rotation;

	ray_dir = ray->dir;
	rotation = ft_rotation_sphere(sphere);
	pos = ft_moins_vector(&ray->start_pos, sphere->pos);
	ft_rotation(pos, rotation);
	ft_rotation(&ray_dir, rotation);
	stmp->a = ray_dir.x * ray_dir.x + ray_dir.y *
	ray_dir.y + ray_dir.z * ray_dir.z;
	stmp->b = 2 * (ray_dir.x * pos->x + ray_dir.y * pos->y
	+ ray_dir.z * pos->z);
	stmp->c = pos->x * pos->x + pos->y * pos->y + pos->z
	* pos->z - (sphere->radius * sphere->radius);
	free(pos);
	return (stmp->b * stmp->b - 4 * stmp->a * stmp->c);
}

int				ft_calc_discri_sphere(t_sphere *sphere, t_ray *ray, t_hit *tmp)
{
	t_tmp_sphere	stmp;

	stmp.delta = ft_discri(ray, &stmp, sphere);
	if (stmp.delta < 0)
		return (0);
	else
	{
		stmp.sphere = sphere;
		stmp.ray = ray;
		stmp.hit = tmp;
		return (ft_calc_sphere_inter(&stmp, sphere));
	}
}

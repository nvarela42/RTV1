/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_cyl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:08:07 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:54:02 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	ft_rotation_cylinder(t_cylinder *cylinder)
{
	t_vector	ret;

	ret.x = -cylinder->rotation->z;
	ret.y = -cylinder->rotation->x;
	ret.z = -cylinder->rotation->y;
	return (ret);
}

static void		ft_cyl_inters(t_tmp_cylinder *ctmp, float t, t_cylinder *cyl)
{
	t_vector		*tmp;
	t_vector		*tmp2;
	t_vector		*tmp3;

	tmp = ft_create_vector("0,0,0");
	tmp->x = ctmp->ray->start_pos.x + ctmp->ray->dir.x * t;
	tmp->y = ctmp->ray->start_pos.y + ctmp->ray->dir.y * t;
	tmp->z = ctmp->ray->start_pos.z + ctmp->ray->dir.z * t;
	tmp2 = ft_moins_vector(tmp, ctmp->cylinder->pos);
	tmp3 = ft_div_vector(tmp2, ctmp->cylinder->radius);
	ctmp->hit->touch = 1;
	ctmp->hit->object = (void*)ctmp->cylinder;
	ctmp->hit->normal = *tmp3;
	ctmp->hit->inter = *tmp;
	ctmp->hit->material = cyl->material;
	free(tmp);
	free(tmp2);
	free(tmp3);
}

static int		ft_calc_cyl_intersect(t_tmp_cylinder *ctmp, t_cylinder *cyl)
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
	ft_cyl_inters(ctmp, t, cyl);
	return (1);
}

static float	ft_discri(t_ray *ray, t_tmp_cylinder *ctmp, t_cylinder *cyl)
{
	t_vector		*pos;
	t_vector		ray_dir;
	t_vector		rotation;

	ray_dir = ray->dir;
	pos = ft_moins_vector(&ray->start_pos, cyl->pos);
	rotation = ft_rotation_cylinder_init();
	ft_rotation(pos, rotation);
	ft_rotation(&ray_dir, rotation);
	rotation = ft_rotation_cylinder(cyl);
	ft_rotation(pos, rotation);
	ft_rotation(&ray_dir, rotation);
	ctmp->a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y;
	ctmp->b = 2 * (ray_dir.x * pos->x + ray_dir.y * pos->y);
	ctmp->c = (pos->x * pos->x + pos->y * pos->y) - cyl->radius * cyl->radius;
	free(pos);
	return (ctmp->b * ctmp->b - 4 * ctmp->a * ctmp->c);
}

int				ft_calc_discri_cyl(t_cylinder *cylinder, t_ray *ray, t_hit *tmp)
{
	t_tmp_cylinder	ctmp;

	ctmp.delta = ft_discri(ray, &ctmp, cylinder);
	if (ctmp.delta < 0)
		return (0);
	else
	{
		ctmp.cylinder = cylinder;
		ctmp.ray = ray;
		ctmp.hit = tmp;
		return (ft_calc_cyl_intersect(&ctmp, cylinder));
	}
}

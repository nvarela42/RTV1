/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_lum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:27:11 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 18:23:11 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_no_lum(t_rtv1 *rtv1, t_pixel *pix)
{
	pix->color = *rtv1->hit.material->material_color;
}

static void	ft_init_ray_lum(t_rtv1 *rtv1, t_ray *ray, t_light *light)
{
	t_vector		*pix_dir;

	pix_dir = ft_moins_vector(&rtv1->hit.inter, light->pos);
	ray->dir = *pix_dir;
	free(pix_dir);
	ray->start_pos = *light->pos;
	ray->dist = ft_vector_magnitude(&ray->dir);
}

static void	ft_final_color(t_rtv1 *rtv1, t_pixel *pix, t_light *light, float d)
{
	t_color				*mat_color;

	mat_color = rtv1->hit.material->material_color;
	pix->color.r += light->light_color->r * d * mat_color->r;
	pix->color.g += light->light_color->g * d * mat_color->g;
	pix->color.b += light->light_color->b * d * mat_color->b;
	if (d > rtv1->hit.material->shiness && d < 1)
	{
		pix->color.r += light->light_color->r * 0.4 * ((d -
		rtv1->hit.material->shiness) / (1 - rtv1->hit.material->shiness));
		pix->color.g += light->light_color->g * 0.4 * ((d -
		rtv1->hit.material->shiness) / (1 - rtv1->hit.material->shiness));
		pix->color.b += light->light_color->b * 0.4 * ((d -
		rtv1->hit.material->shiness) / (1 - rtv1->hit.material->shiness));
	}
	pix->color.r = pix->color.r > 1 ? 1 : pix->color.r;
	pix->color.g = pix->color.g > 1 ? 1 : pix->color.g;
	pix->color.b = pix->color.b > 1 ? 1 : pix->color.b;
}

static void	ft_calc_color(t_rtv1 *rtv1, t_pixel *pix, t_light *light)
{
	float				dot;
	t_vector			*light_vect;

	light_vect = ft_moins_vector(light->pos, &rtv1->hit.inter);
	ft_vector_normalize(light_vect);
	ft_vector_normalize(&rtv1->hit.normal);
	dot = ft_vector_dot_mult(&rtv1->hit.normal, light_vect);
	free(light_vect);
	if (dot < 0)
		return ;
	ft_final_color(rtv1, pix, light, dot);
}

void		ft_calc_lum(t_rtv1 *rtv1, t_pixel *pix)
{
	t_ray				light_ray;
	int					blocked;
	t_light				*light;

	light = rtv1->light;
	if (!light)
		ft_no_lum(rtv1, pix);
	while (light)
	{
		blocked = 0;
		ft_init_ray_lum(rtv1, &light_ray, light);
		ft_lum_hit_sphere(rtv1, rtv1->sphere, &light_ray, &blocked);
		ft_lum_hit_plane(rtv1, rtv1->plane, &light_ray, &blocked);
		ft_lum_hit_cyl(rtv1, rtv1->cylinder, &light_ray, &blocked);
		ft_lum_hit_cone(rtv1, rtv1->cone, &light_ray, &blocked);
		if (!blocked)
			ft_calc_color(rtv1, pix, light);
		light = light->next;
	}
}

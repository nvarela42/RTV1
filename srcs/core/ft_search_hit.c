/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 07:07:37 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/25 01:19:52 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector		*ft_calc_pix_dir(t_camera *cam, int x, int y)
{
	t_vector		*tmp;
	float			indent_x;
	float			indent_y;

	indent_x = cam->viewport_w / (float)cam->size_x;
	indent_y = cam->viewport_h / (float)cam->size_y;
	tmp = ft_create_vector("0,0,0");
	tmp->x = (cam->up_left->x + cam->right->x * indent_x * x -
	cam->up->x * indent_y * y) - cam->pos->x;
	tmp->y = (cam->up_left->y + cam->right->y * indent_x * x -
	cam->up->y * indent_y * y) - cam->pos->y;
	tmp->z = (cam->up_left->z + cam->right->z * indent_x * x -
	cam->up->z * indent_y * y) - cam->pos->z;
	return (tmp);
}

static void			ft_init_ray(t_rtv1 *rtv1, t_ray *ray, int x, int y)
{
	t_vector		*pix_dir;

	pix_dir = ft_calc_pix_dir(rtv1->camera, x, y);
	ray->dir.x = pix_dir->x;
	ray->dir.y = pix_dir->y;
	ray->dir.z = pix_dir->z;
	free(pix_dir);
	ft_vector_normalize(&ray->dir);
	ray->dist = DEFAULT_DISTANCE;
}

void				ft_search_hit(t_rtv1 *rtv1, int x, int y, t_ray *ray)
{
	ft_init_ray(rtv1, ray, x, y);
	rtv1->hit.touch = 0;
	rtv1->hit.object = NULL;
	ft_search_sphere_hit(rtv1, rtv1->sphere, ray);
	ft_search_plane_hit(rtv1, rtv1->plane, ray);
	ft_search_cylinder_hit(rtv1, rtv1->cylinder, ray);
	ft_search_cone_hit(rtv1, rtv1->cone, ray);
}

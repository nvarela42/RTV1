/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:26:47 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/29 20:35:56 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			ft_fill_camera_top_left(t_camera *camera)
{
	camera->up_left = ft_create_vector("0, 0, 0");
	camera->up_left->x = camera->pos->x + ((camera->dir->x *
	camera->dist) + (camera->up->x * (camera->viewport_h / 2.0f))) -
	(camera->right->x * (camera->viewport_w / 2.0f));
	camera->up_left->y = camera->pos->y + ((camera->dir->y *
	camera->dist) + (camera->up->y * (camera->viewport_h / 2.0f))) -
	(camera->right->y * (camera->viewport_w / 2.0f));
	camera->up_left->z = camera->pos->z + ((camera->dir->z *
	camera->dist) + (camera->up->z * (camera->viewport_h / 2.0f))) -
	(camera->right->z * (camera->viewport_w / 2.0f));
}

void				ft_init_camera(t_rtv1 *rtv1, void *obj)
{
	t_camera		*camera;

	if (ft_size_darray(rtv1->var->data) != 3)
		ft_print_error("Error in camera number parameters", TRUE);
	camera = (t_camera*)obj;
	camera->pos = ft_create_vector(rtv1->var->data[0]);
	camera->lookat = ft_create_vector(rtv1->var->data[1]);
	camera->up = ft_create_vector(rtv1->var->data[2]);
	camera->dist = 1;
	camera->viewport_w = 0.50;
	camera->viewport_h = 0.35;
	camera->dir = ft_moins_vector(camera->lookat, camera->pos);
	ft_vector_normalize(camera->dir);
	camera->right = ft_mult_vector(camera->up, camera->dir);
	free(camera->up);
	camera->up = ft_mult_vector(camera->dir, camera->right);
	camera->size_x = 1280;
	camera->size_y = 960;
	ft_fill_camera_top_left(camera);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:26:10 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/06 02:50:26 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				*ft_create_camera(t_rtv1 *rtv1)
{
	if (rtv1->camera)
		ft_free_camera(rtv1);
	if ((rtv1->camera = (t_camera*)malloc(sizeof(t_camera))) == NULL)
		ft_perror(TRUE);
	rtv1->camera->pos = NULL;
	rtv1->camera->lookat = NULL;
	rtv1->camera->up = NULL;
	rtv1->camera->dir = NULL;
	rtv1->camera->right = NULL;
	rtv1->camera->up_left = NULL;
	rtv1->camera->dist = 0;
	rtv1->camera->viewport_w = 0;
	rtv1->camera->viewport_h = 0;
	rtv1->camera->size_x = 0;
	rtv1->camera->size_y = 0;
	return ((void*)rtv1->camera);
}

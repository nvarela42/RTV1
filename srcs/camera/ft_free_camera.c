/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:26:34 by agoomany          #+#    #+#             */
/*   Updated: 2018/01/24 14:26:39 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_camera(t_rtv1 *rtv1)
{
	t_camera			*camera;

	camera = rtv1->camera;
	if (!camera)
		return ;
	free(camera->pos);
	free(camera->lookat);
	free(camera->up);
	free(camera->dir);
	free(camera->right);
	free(camera->up_left);
	free(camera);
	rtv1->camera = NULL;
}

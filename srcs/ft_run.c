/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:51 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/30 06:12:17 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void				ft_check_mandatory(t_rtv1 *rtv1)
{
	if (!rtv1->camera)
		ft_print_error("Scene file must contain a camera.", TRUE);
	if (!rtv1->material)
		ft_print_error("Scene file must contain a material.", TRUE);
	if (!rtv1->nb_object)
		ft_print_error("Scene file must contain a object.", TRUE);
}

void					ft_run(t_rtv1 *rtv1)
{
	t_ray				ray;

	ft_check_mandatory(rtv1);
	ray.start_pos = *rtv1->camera->pos;
	ft_link_material_object(rtv1);
	ft_ray(rtv1, &ray);
	ft_create_sdl(rtv1);
	ft_init_sdl(rtv1);
	ft_loop_sdl(rtv1->sdl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_rtv1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:59 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/28 22:49:01 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_rtv1(t_rtv1 *rtv1)
{
	if (!rtv1)
		return ;
	ft_free_camera(rtv1);
	ft_free_sdl(rtv1);
	ft_free_var(rtv1);
	free(rtv1->pixels);
	ft_free_sphere(rtv1);
	ft_free_plane(rtv1);
	ft_free_cylinder(rtv1);
	ft_free_cone(rtv1);
	ft_free_material(rtv1);
	ft_free_light(rtv1);
	free(rtv1);
}

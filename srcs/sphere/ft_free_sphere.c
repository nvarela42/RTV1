/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:31:02 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/25 21:43:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_sphere(t_rtv1 *rtv1)
{
	t_sphere			*sphere;
	t_sphere			*tmp;

	sphere = rtv1->sphere;
	if (!sphere)
		return ;
	while (sphere)
	{
		tmp = sphere->next;
		free(sphere->pos);
		free(sphere->rotation);
		free(sphere->translation);
		free(sphere);
		sphere = tmp;
	}
	rtv1->sphere = NULL;
}

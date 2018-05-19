/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:40 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/29 12:15:51 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_plane(t_rtv1 *rtv1)
{
	t_plane				*plane;
	t_plane				*tmp;

	plane = rtv1->plane;
	if (!plane)
		return ;
	while (plane)
	{
		tmp = plane->next;
		free(plane->pos);
		free(plane->normale);
		free(plane->translation);
		free(plane);
		plane = tmp;
	}
	rtv1->plane = NULL;
}

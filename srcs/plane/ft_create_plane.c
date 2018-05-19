/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:34 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/29 12:15:35 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_plane		*ft_get_last_plane(t_rtv1 *rtv1)
{
	t_plane			*current;

	current = rtv1->plane;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void				*ft_create_plane(t_rtv1 *rtv1)
{
	t_plane			*tmp;
	t_plane			*current;

	if ((tmp = (t_plane*)malloc(sizeof(t_plane))) == NULL)
		ft_perror(TRUE);
	tmp->pos = NULL;
	tmp->normale = NULL;
	tmp->translation = NULL;
	tmp->material_id = 0;
	tmp->material = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_plane(rtv1)) == NULL)
		rtv1->plane = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:37:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:49:35 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_cylinder		*ft_get_last_cylinder(t_rtv1 *rtv1)
{
	t_cylinder			*current;

	current = rtv1->cylinder;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void					*ft_create_cylinder(t_rtv1 *rtv1)
{
	t_cylinder			*tmp;
	t_cylinder			*current;

	if ((tmp = (t_cylinder*)malloc(sizeof(t_cylinder))) == NULL)
		ft_perror(TRUE);
	tmp->pos = NULL;
	tmp->radius = 0;
	tmp->material = NULL;
	tmp->rotation = NULL;
	tmp->translation = NULL;
	tmp->material_id = 0;
	tmp->material = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_cylinder(rtv1)) == NULL)
		rtv1->cylinder = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}

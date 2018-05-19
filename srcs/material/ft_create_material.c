/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:44 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 13:46:17 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_material		*ft_get_last_material(t_rtv1 *rtv1)
{
	t_material		*current;

	current = rtv1->material;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void					*ft_create_material(t_rtv1 *rtv1)
{
	t_material		*tmp;
	t_material		*current;

	if ((tmp = (t_material*)malloc(sizeof(t_material))) == NULL)
		ft_perror(TRUE);
	tmp->material_color = NULL;
	tmp->shiness = 0;
	tmp->next = NULL;
	if ((current = ft_get_last_material(rtv1)) == NULL)
	{
		tmp->material_id = 1;
		rtv1->material = tmp;
	}
	else
	{
		tmp->material_id = current->material_id + 1;
		current->next = tmp;
	}
	return ((void*)tmp);
}

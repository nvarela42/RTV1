/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:30:56 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/25 21:43:06 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_sphere		*ft_get_last_sphere(t_rtv1 *rtv1)
{
	t_sphere		*current;

	current = rtv1->sphere;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void				*ft_create_sphere(t_rtv1 *rtv1)
{
	t_sphere		*tmp;
	t_sphere		*current;

	if ((tmp = (t_sphere*)malloc(sizeof(t_sphere))) == NULL)
		ft_perror(TRUE);
	tmp->pos = NULL;
	tmp->radius = 0;
	tmp->rotation = NULL;
	tmp->translation = NULL;
	tmp->material_id = 0;
	tmp->material = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_sphere(rtv1)) == NULL)
		rtv1->sphere = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}

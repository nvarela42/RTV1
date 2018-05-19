/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:45:15 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/30 06:19:22 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_cone		*ft_get_last_cone(t_rtv1 *rtv1)
{
	t_cone			*current;

	current = rtv1->cone;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void				*ft_create_cone(t_rtv1 *rtv1)
{
	t_cone			*tmp;
	t_cone			*current;

	if ((tmp = (t_cone*)malloc(sizeof(t_cone))) == NULL)
		ft_perror(TRUE);
	tmp->pos = NULL;
	tmp->radius = 0;
	tmp->material_id = 0;
	tmp->material = NULL;
	tmp->rotation = NULL;
	tmp->translation = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_cone(rtv1)) == NULL)
		rtv1->cone = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}

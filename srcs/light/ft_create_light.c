/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:27:58 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/30 06:57:05 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_light		*ft_get_last_light(t_rtv1 *rtv1)
{
	t_light			*current;

	current = rtv1->light;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void				*ft_create_light(t_rtv1 *rtv1)
{
	t_light			*tmp;
	t_light			*current;

	if ((tmp = (t_light*)malloc(sizeof(t_light))) == NULL)
		ft_perror(TRUE);
	tmp->pos = NULL;
	tmp->light_color = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_light(rtv1)) == NULL)
		rtv1->light = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}

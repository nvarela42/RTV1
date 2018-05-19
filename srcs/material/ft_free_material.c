/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:55 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/01 21:11:30 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_material(t_rtv1 *rtv1)
{
	t_material			*material;
	t_material			*tmp;

	material = rtv1->material;
	if (!material)
		return ;
	while (material)
	{
		tmp = material->next;
		free(material->material_color);
		free(material);
		material = tmp;
	}
	rtv1->material = NULL;
}

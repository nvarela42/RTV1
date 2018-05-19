/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:16:28 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:42:46 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_material			*ft_get_material(t_material *material, int i)
{
	while (material)
	{
		if (material->material_id == i)
			return (material);
		material = material->next;
	}
	return (material);
}

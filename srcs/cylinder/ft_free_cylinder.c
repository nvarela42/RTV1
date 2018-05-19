/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:30:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/28 23:08:29 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_cylinder(t_rtv1 *rtv1)
{
	t_cylinder				*cylinder;
	t_cylinder				*tmp;

	cylinder = rtv1->cylinder;
	if (!cylinder)
		return ;
	while (cylinder)
	{
		tmp = cylinder->next;
		free(cylinder->pos);
		free(cylinder->rotation);
		free(cylinder->translation);
		free(cylinder);
		cylinder = tmp;
	}
	rtv1->cylinder = NULL;
}

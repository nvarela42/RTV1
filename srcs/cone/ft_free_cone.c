/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:30:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/28 23:08:58 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_cone(t_rtv1 *rtv1)
{
	t_cone				*cone;
	t_cone				*tmp;

	cone = rtv1->cone;
	if (!cone)
		return ;
	while (cone)
	{
		tmp = cone->next;
		free(cone->pos);
		free(cone->rotation);
		free(cone->translation);
		free(cone);
		cone = tmp;
	}
	rtv1->cone = NULL;
}

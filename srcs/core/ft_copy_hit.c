/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 22:51:56 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/25 22:52:22 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_copy_hit(t_rtv1 *rtv1, t_hit tmp)
{
	rtv1->hit.touch = tmp.touch;
	rtv1->hit.object = tmp.object;
	rtv1->hit.inter.x = tmp.inter.x;
	rtv1->hit.inter.y = tmp.inter.y;
	rtv1->hit.inter.z = tmp.inter.z;
	rtv1->hit.normal.x = tmp.normal.x;
	rtv1->hit.normal.y = tmp.normal.y;
	rtv1->hit.normal.z = tmp.normal.z;
	rtv1->hit.material = tmp.material;
}

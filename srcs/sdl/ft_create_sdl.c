/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:30:14 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:39:44 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			ft_create_sdl(t_rtv1 *rtv1)
{
	if ((rtv1->sdl = (t_sdl*)malloc(sizeof(t_sdl))) == NULL)
		ft_perror(TRUE);
	rtv1->sdl->win = NULL;
	rtv1->sdl->renderer = NULL;
	rtv1->sdl->texture = NULL;
	rtv1->sdl->pixels = NULL;
}

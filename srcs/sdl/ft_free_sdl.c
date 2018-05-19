/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:30:20 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:39:43 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void						ft_free_sdl(t_rtv1 *rtv1)
{
	t_sdl					*sdl;

	sdl = rtv1->sdl;
	if (!sdl)
		return ;
	if (rtv1->var->sdl_ok == 0)
		return ;
	if (sdl->pixels)
		free(sdl->pixels);
	if (sdl->texture)
		SDL_DestroyTexture(sdl->texture);
	if (sdl->renderer)
		SDL_DestroyRenderer(sdl->renderer);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	if (rtv1->var->sdl_ok)
		SDL_Quit();
	free(rtv1->sdl);
	rtv1->sdl = NULL;
}

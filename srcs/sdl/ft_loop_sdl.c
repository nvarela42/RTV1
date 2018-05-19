/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:30:41 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:39:42 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_loop_sdl(t_sdl *sdl)
{
	SDL_Event			event;

	while (1)
	{
		if (SDL_UpdateTexture(sdl->texture, NULL, sdl->pixels, sdl->pitch) != 0)
			ft_print_error((char*)SDL_GetError(), TRUE);
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			return ;
		if (SDL_RenderClear(sdl->renderer) != 0)
			ft_print_error((char*)SDL_GetError(), TRUE);
		if (SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL) != 0)
			ft_print_error((char*)SDL_GetError(), TRUE);
		SDL_RenderPresent(sdl->renderer);
	}
}

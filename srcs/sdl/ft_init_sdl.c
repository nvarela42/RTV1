/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:30:28 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/29 19:59:11 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static Uint32		ft_get_sdl_color(t_pixel *pixel)
{
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8			a;

	r = pixel->color.r * 255;
	g = pixel->color.g * 255;
	b = pixel->color.b * 255;
	a = pixel->color.t * 255;
	return ((unsigned char)r << 24 | (unsigned char)g << 16 |
	(unsigned char)b << 8 | (unsigned char)a);
}

static void			ft_copy_pixel_pixel(t_pixel *rt, Uint32 *sdl, t_rtv1 *rtv1)
{
	int				x;
	int				y;
	int				i;

	y = 0;
	i = 0;
	while (y < rtv1->camera->size_y)
	{
		x = 0;
		while (x < rtv1->camera->size_x)
		{
			sdl[i] = ft_get_sdl_color(&rt[i]);
			x++;
			i++;
		}
		y++;
	}
}

void				ft_init_sdl(t_rtv1 *rtv1)
{
	t_sdl			*sdl;
	int				x_size;
	int				y_size;
	uint			xy;

	sdl = rtv1->sdl;
	x_size = rtv1->camera->size_x;
	y_size = rtv1->camera->size_y;
	if ((sdl->win = SDL_CreateWindow(SDL_TITLE, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, x_size, y_size, 0)) == NULL)
		ft_print_error((char*)SDL_GetError(), TRUE);
	if ((sdl->renderer = SDL_CreateRenderer(sdl->win, -1, 0)) == NULL)
		ft_print_error((char*)SDL_GetError(), TRUE);
	if ((sdl->texture = SDL_CreateTexture(sdl->renderer,
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
		x_size, y_size)) == NULL)
		ft_print_error((char*)SDL_GetError(), TRUE);
	xy = x_size * y_size;
	if ((sdl->pixels = (Uint32*)malloc(sizeof(Uint32) * xy)) == NULL)
		ft_perror(TRUE);
	sdl->pitch = x_size * sizeof(Uint32);
	ft_copy_pixel_pixel(rtv1->pixels, sdl->pixels, rtv1);
}

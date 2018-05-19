/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:30:02 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/31 16:57:45 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			ft_init_pix(t_pixel *pix, int x, int y)
{
	pix->x = x;
	pix->y = y;
	pix->color = (t_color){DEFAULT_R, DEFAULT_G, DEFAULT_B, DEFAULT_T};
}

static void			ft_run_rt(t_rtv1 *rtv1, t_pixel *pix, int size, t_ray *ray)
{
	int				x;
	int				y;
	int				i;

	x = 0;
	y = 0;
	i = 0;
	while (i < size)
	{
		if (x == rtv1->camera->size_x)
		{
			x = 0;
			y++;
		}
		ft_init_pix(&pix[i], x, y);
		ft_search_hit(rtv1, x, y, ray);
		if (rtv1->hit.touch)
			ft_calc_lum(rtv1, &pix[i]);
		x++;
		i++;
	}
}

void				ft_ray(t_rtv1 *rtv1, t_ray *ray)
{
	int				size;

	if (rtv1->camera->size_x <= 0 || rtv1->camera->size_y <= 0)
		ft_print_error("Error in viewport size.", TRUE);
	size = rtv1->camera->size_x * rtv1->camera->size_y;
	if ((rtv1->pixels = (t_pixel*)malloc(sizeof(t_pixel) * size)) == NULL)
		ft_perror(TRUE);
	rtv1->hit.touch = 0;
	rtv1->hit.object = NULL;
	ft_run_rt(rtv1, rtv1->pixels, size, ray);
}

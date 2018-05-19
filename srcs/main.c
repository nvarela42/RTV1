/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:57 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/30 06:12:09 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				begin(void)
{
	ft_glob();
}

int					main(int argc, char **argv)
{
	t_rtv1			*rtv1;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putendl_fd(SDL_GetError(), 2);
		exit(EXIT_FAILURE);
	}
	ft_glob()->var->sdl_ok = 1;
	rtv1 = ft_glob();
	ft_init(rtv1, argc, argv);
	ft_run(rtv1);
	ft_free_sdl(rtv1);
	return (EXIT_SUCCESS);
}

void				end(void)
{
	if (ft_glob())
		ft_free_rtv1(ft_glob());
}

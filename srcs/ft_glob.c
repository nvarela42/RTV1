/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:14 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/29 23:47:36 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void						ft_fill_object_create(t_rtv1 *rtv1)
{
	rtv1->var->object_create[0] = &ft_create_camera;
	rtv1->var->object_create[1] = &ft_create_sphere;
	rtv1->var->object_create[2] = &ft_create_plane;
	rtv1->var->object_create[3] = &ft_create_cylinder;
	rtv1->var->object_create[4] = &ft_create_cone;
	rtv1->var->object_create[5] = &ft_create_material;
	rtv1->var->object_create[6] = &ft_create_light;
	rtv1->var->object_create[7] = &ft_create_bad_object;
}

static void						ft_fill_object_init(t_rtv1 *rtv1)
{
	rtv1->var->object_init[0] = &ft_init_camera;
	rtv1->var->object_init[1] = &ft_init_sphere;
	rtv1->var->object_init[2] = &ft_init_plane;
	rtv1->var->object_init[3] = &ft_init_cylinder;
	rtv1->var->object_init[4] = &ft_init_cone;
	rtv1->var->object_init[5] = &ft_init_material;
	rtv1->var->object_init[6] = &ft_init_light;
}

static void						ft_fill_object(t_rtv1 *rtv1)
{
	int							len;

	if ((rtv1->var->object = ft_strsplit_trim(OBJ, ';')) == NULL)
		ft_print_error("Error in parameters", TRUE);
	len = ft_size_darray(rtv1->var->object) + 1;
	if ((rtv1->var->object_create =
		(t_object_create**)malloc(sizeof(t_object_create*) * len)) == NULL)
		ft_perror(TRUE);
	len--;
	if ((rtv1->var->object_init =
		(t_object_init**)malloc(sizeof(t_object_init*) * len)) == NULL)
		ft_perror(TRUE);
}

static void						ft_init_glob(t_rtv1 *rtv1)
{
	rtv1->camera = NULL;
	if ((rtv1->var = (t_var*)malloc(sizeof(t_var))) == NULL)
		ft_perror(TRUE);
	rtv1->var->data = NULL;
	rtv1->var->sdl_ok = 0;
	rtv1->var->fd = -1;
	rtv1->var->object = NULL;
	rtv1->var->object_create = NULL;
	rtv1->var->object_init = NULL;
	rtv1->pixels = NULL;
	rtv1->sdl = NULL;
	rtv1->sphere = NULL;
	rtv1->plane = NULL;
	rtv1->cylinder = NULL;
	rtv1->cone = NULL;
	rtv1->material = NULL;
	rtv1->light = NULL;
	rtv1->nb_object = 0;
}

t_rtv1							*ft_glob(void)
{
	static t_rtv1			*rtv1 = NULL;
	static int				pass = 0;

	if (pass == 0)
	{
		pass = 1;
		if ((rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1))) == NULL)
			ft_perror(TRUE);
		ft_init_glob(rtv1);
		ft_fill_object(rtv1);
		ft_fill_object_create(rtv1);
		ft_fill_object_init(rtv1);
	}
	return (rtv1);
}

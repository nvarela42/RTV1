/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:20 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/16 14:01:20 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int						ft_search_object_in_db(t_rtv1 *rtv1, char *obj)
{
	int							i;

	i = 0;
	while (rtv1->var->object[i] != NULL)
	{
		if (!ft_strcmp(rtv1->var->object[i], obj))
			return (i);
		i++;
	}
	return (i);
}

static void						ft_create_object(t_rtv1 *rtv1, char *str)
{
	char						**array;
	int							i;
	void						*obj;

	array = ft_strsplit_trim(str, ':');
	free(str);
	if (!array)
		ft_perror(TRUE);
	if (ft_size_darray(array) != 2)
	{
		ft_free_darray(array);
		ft_print_error("Bad format in your scene file.", TRUE);
	}
	i = ft_search_object_in_db(rtv1, array[0]);
	rtv1->var->data = ft_strsplit_trim(array[1], ';');
	ft_free_darray(array);
	if (!rtv1->var->data)
		ft_perror(TRUE);
	obj = (*rtv1->var->object_create[i])(rtv1);
	(*rtv1->var->object_init[i])(rtv1, obj);
	ft_free_darray(rtv1->var->data);
	rtv1->var->data = NULL;
}

static void						ft_read_file(t_rtv1 *rtv1, int fd)
{
	char						*line;
	char						*trim;

	while (get_next_line(fd, &line) == 1)
	{
		trim = ft_strtrim(line);
		free(line);
		if (!trim)
			ft_perror(TRUE);
		if (trim[0] == '#')
		{
			trim[0] = ' ';
			ft_create_object(rtv1, trim);
		}
		else
			free(trim);
	}
}

void							ft_init(t_rtv1 *rtv1, int ac, char **av)
{
	if (ac != 2)
		ft_print_error("Missing scene filename.", TRUE);
	if ((rtv1->var->fd = open(av[1], O_RDONLY)) == -1)
		ft_perror(TRUE);
	ft_read_file(rtv1, rtv1->var->fd);
}

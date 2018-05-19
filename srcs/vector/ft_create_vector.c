/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:21 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 16:59:05 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int				ft_affect_data_vector(t_vector *tmp, char **array)
{
	if (array[0][0] == '\0' || !array[0] || array[1][0] == '\0' || !array[1]
	|| array[2][0] == '\0' || !array[2])
		return (1);
	tmp->x = ft_atof(array[0]);
	tmp->y = ft_atof(array[1]);
	tmp->z = ft_atof(array[2]);
	return (0);
}

static void				ft_check_isnum_sign(char **array)
{
	int					i;

	i = 0;
	while (i < 3)
	{
		if (array[i][0] == '.' || ft_isalldigit_sign(array[i]))
		{
			ft_free_darray(array);
			ft_print_error("Error with vector. Must be only number.", TRUE);
		}
		i++;
	}
}

t_vector				*ft_create_vector(char *str)
{
	t_vector			*tmp;
	char				**array;

	array = ft_strsplit_trim(str, ',');
	if (!array || ft_size_darray(array) != 3)
	{
		ft_free_darray(array);
		ft_print_error("Error while creating vector", TRUE);
	}
	ft_check_isnum_sign(array);
	if ((tmp = (t_vector*)malloc(sizeof(t_vector))) == NULL)
		ft_perror(TRUE);
	if (ft_affect_data_vector(tmp, array) == 1)
	{
		ft_free_darray(array);
		free(tmp);
		ft_print_error("Error while creating vector", TRUE);
	}
	ft_free_darray(array);
	return (tmp);
}

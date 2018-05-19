/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:27:09 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 16:45:58 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int				ft_affect_data_vector(t_color *tmp, char **array)
{
	if (array[0][0] == '\0' || !array[0] || array[1][0] == '\0' ||
	!array[1] || array[2][0] == '\0' || !array[2])
		return (1);
	tmp->r = ft_atof(array[0]);
	tmp->g = ft_atof(array[1]);
	tmp->b = ft_atof(array[2]);
	tmp->t = DEFAULT_T;
	return (0);
}

static void				ft_check_isnum_sign_color(char **array)
{
	int					i;

	i = 0;
	while (i < 3)
	{
		if (array[i][0] == '.' || ft_isalldigit_sign(array[i]))
		{
			ft_free_darray(array);
			ft_print_error("Error with color. Must be only number.", TRUE);
		}
		i++;
	}
}

static void				ft_check_range_color(t_color *tmp, char **array)
{
	int					flag;

	flag = 0;
	if (tmp->r > 1 || tmp->r < 0)
		flag = 1;
	if (tmp->g > 1 || tmp->g < 0)
		flag = 1;
	if (tmp->b > 1 || tmp->b < 0)
		flag = 1;
	if (tmp->t > 1 || tmp->t < 0)
		flag = 1;
	if (flag)
	{
		free(tmp);
		ft_free_darray(array);
		ft_print_error("Error with color. Must be in range [0-1].", TRUE);
	}
}

t_color					*ft_create_color(char *str)
{
	t_color				*tmp;
	char				**array;

	array = ft_strsplit_trim(str, ',');
	if (!array || ft_size_darray(array) != 3)
	{
		ft_free_darray(array);
		ft_print_error("Error while creating color. Must be r,g,b", TRUE);
	}
	ft_check_isnum_sign_color(array);
	if ((tmp = (t_color*)malloc(sizeof(t_color))) == NULL)
		ft_perror(TRUE);
	if (ft_affect_data_vector(tmp, array) == 1)
	{
		ft_free_darray(array);
		free(tmp);
		ft_print_error("Error while creating color. Must be r,g,b", TRUE);
	}
	ft_check_range_color(tmp, array);
	ft_free_darray(array);
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_on_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:14 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/18 09:25:45 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector			*ft_div_vector(t_vector *vector, float val)
{
	t_vector		*ret;

	ret = ft_create_vector("0,0,0");
	ret->x = vector->x / val;
	ret->y = vector->y / val;
	ret->z = vector->z / val;
	return (ret);
}

t_vector			*ft_mult_num_vector(t_vector *a, int i)
{
	t_vector		*ret;

	ret = ft_create_vector("0,0,0");
	ret->x = a->x * i;
	ret->y = a->y * i;
	ret->z = a->z * i;
	return (ret);
}

t_vector			*ft_plus_vector(t_vector *a, t_vector *b)
{
	t_vector		*ret;

	ret = ft_create_vector("0,0,0");
	ret->x = a->x + b->x;
	ret->y = a->y + b->y;
	ret->z = a->z + b->z;
	return (ret);
}

t_vector			*ft_mult_vector(t_vector *a, t_vector *b)
{
	t_vector		*ret;

	ret = ft_create_vector("0,0,0");
	ret->x = (a->y * b->z) - (a->z * b->y);
	ret->y = (a->z * b->x) - (a->x * b->z);
	ret->z = (a->x * b->y) - (a->y * b->x);
	return (ret);
}

t_vector			*ft_moins_vector(t_vector *a, t_vector *b)
{
	t_vector		*ret;

	ret = ft_create_vector("0,0,0");
	ret->x = a->x - b->x;
	ret->y = a->y - b->y;
	ret->z = a->z - b->z;
	return (ret);
}

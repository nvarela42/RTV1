/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:25 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/09 01:41:25 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_vector_normalize(t_vector *vector)
{
	float			val;

	val = ft_vector_magnitude(vector);
	vector->x /= val;
	vector->y /= val;
	vector->z /= val;
}

float					ft_vector_magnitude(t_vector *vector)
{
	float				val;

	val = ft_vector_square_len(vector);
	return (sqrt(val));
}

float					ft_vector_square_len(t_vector *vector)
{
	float				val;

	val = (vector->x * vector->x);
	val += (vector->y * vector->y);
	val += (vector->z * vector->z);
	return (val);
}

float					ft_vector_dot_mult(t_vector *a, t_vector *b)
{
	float				val;

	val = (a->x * b->x);
	val += (a->y * b->y);
	val += (a->z * b->z);
	return (val);
}

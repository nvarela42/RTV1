/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bad_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:53 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:34:57 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					*ft_create_bad_object(t_rtv1 *rtv1)
{
	ft_print_error("Bad object. Check your scene file", TRUE);
	return ((void*)rtv1);
}

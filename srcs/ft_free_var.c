/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:06 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/18 05:47:19 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_free_var(t_rtv1 *rtv1)
{
	t_var				*var;

	var = rtv1->var;
	if (!var)
		return ;
	ft_free_darray(var->data);
	if (var->fd != -1)
		close(var->fd);
	ft_free_darray(var->object);
	free(var->object_create);
	free(var->object_init);
	free(var);
	rtv1->var = NULL;
}

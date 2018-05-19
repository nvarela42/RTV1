/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:36:31 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:35:58 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					ft_print_error(char *str, t_bool exit_flag)
{
	ft_putstr_fd("rtv1: ", 2);
	ft_putendl_fd(str, 2);
	if (exit_flag)
		exit(EXIT_FAILURE);
}

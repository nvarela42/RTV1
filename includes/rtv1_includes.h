/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_includes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:27:23 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/25 01:13:48 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_INCLUDES_H
# define RTV1_INCLUDES_H

/*
** INCLUDES
*/
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <float.h>
# include <SDL2/SDL.h>
# include "libft.h"
/*
** DEFINE
*/
# define SDL_TITLE "RTV1"
# define OBJ "CAMERA;SPHERE;PLANE;CYLINDER;CONE;MATERIAL;LIGHT"
# define DEFAULT_R 0
# define DEFAULT_G 0
# define DEFAULT_B 0
# define DEFAULT_T 1
# define DEFAULT_DISTANCE 999999

#endif

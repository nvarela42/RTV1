/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:27:17 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 13:46:19 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H

# include "rtv1_includes.h"

/*
** TYPEDEF
*/
typedef struct s_sdl				t_sdl;
typedef struct s_var				t_var;
typedef struct s_vector				t_vector;
typedef struct s_color				t_color;
typedef struct s_camera				t_camera;
typedef struct s_sphere				t_sphere;
typedef struct s_plane				t_plane;
typedef struct s_cylinder			t_cylinder;
typedef struct s_cone				t_cone;
typedef struct s_light				t_light;
typedef struct s_material			t_material;
typedef struct s_pixel				t_pixel;
typedef struct s_ray				t_ray;
typedef struct s_hit				t_hit;
typedef struct s_tmp_sphere			t_tmp_sphere;
typedef struct s_tmp_plane			t_tmp_plane;
typedef struct s_tmp_cylinder		t_tmp_cylinder;
typedef struct s_tmp_cone			t_tmp_cone;
typedef struct s_rtv1				t_rtv1;
typedef void						*(t_object_create)(t_rtv1*);
typedef void						(t_object_init)(t_rtv1*, void*);

/*
** STRUCT
*/
struct								s_sphere
{
	t_vector						*pos;
	float							radius;
	t_vector						*rotation;
	t_vector						*translation;
	int								material_id;
	t_material						*material;
	t_sphere						*next;
};

struct								s_tmp_sphere
{
	float							a;
	float							b;
	float							c;
	float							delta;
	t_sphere						*sphere;
	t_ray							*ray;
	t_hit							*hit;
};

struct								s_plane
{
	t_vector						*pos;
	t_vector						*normale;
	t_vector						*translation;
	int								material_id;
	t_material						*material;
	t_plane							*next;
};

struct								s_tmp_plane
{
	float							a;
	float							b;
	float							c;
	float							delta;
	t_plane							*plane;
	t_ray							*ray;
	t_hit							*hit;
};

struct								s_cylinder
{
	t_vector						*pos;
	float							radius;
	t_vector						*rotation;
	t_vector						*translation;
	int								material_id;
	t_material						*material;
	t_cylinder						*next;
};

struct								s_tmp_cylinder
{
	float							a;
	float							b;
	float							c;
	float							delta;
	t_cylinder						*cylinder;
	t_ray							*ray;
	t_hit							*hit;
};

struct								s_cone
{
	t_vector						*pos;
	float							radius;
	t_vector						*rotation;
	t_vector						*translation;
	int								material_id;
	t_material						*material;
	t_cone							*next;
};

struct								s_tmp_cone
{
	float							a;
	float							b;
	float							c;
	float							delta;
	t_cone							*cone;
	t_ray							*ray;
	t_hit							*hit;
};

struct								s_light
{
	t_vector						*pos;
	t_color							*light_color;
	t_light							*next;
};

struct								s_material
{
	int								material_id;
	t_color							*material_color;
	float							shiness;
	t_material						*next;
};

struct								s_camera
{
	t_vector						*pos;
	t_vector						*lookat;
	t_vector						*up;
	t_vector						*dir;
	t_vector						*right;
	t_vector						*up_left;
	float							dist;
	float							viewport_w;
	float							viewport_h;
	int								size_x;
	int								size_y;
};

struct								s_vector
{
	float							x;
	float							y;
	float							z;
};

struct								s_color
{
	float							r;
	float							g;
	float							b;
	float							t;
};

struct								s_pixel
{
	int								x;
	int								y;
	t_color							color;
};

struct								s_var
{
	int								sdl_ok;
	char							**data;
	int								fd;
	char							**object;
	t_object_create					**object_create;
	t_object_init					**object_init;
};

struct								s_ray
{
	t_vector						start_pos;
	t_vector						dir;
	float							dist;
};

struct								s_sdl
{
	SDL_Window						*win;
	SDL_Renderer					*renderer;
	SDL_Texture						*texture;
	Uint32							*pixels;
	int								pitch;
};

struct								s_hit
{
	int								touch;
	void							*object;
	t_vector						inter;
	t_vector						normal;
	t_material						*material;
};

struct								s_rtv1
{
	t_camera						*camera;
	t_var							*var;
	t_pixel							*pixels;
	t_sdl							*sdl;
	t_sphere						*sphere;
	t_plane							*plane;
	t_cylinder						*cylinder;
	t_cone							*cone;
	t_material						*material;
	t_light							*light;
	int								nb_object;
	t_hit							hit;
};

/*
** GLOBALES
*/

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:27:27 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/31 17:44:59 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "rtv1_structs.h"

/*
** PROTOTYPES - RTV1t_link_mat_cylinder
*/
void					begin(void) __attribute__((constructor));
void					end(void) __attribute__((destructor));
t_rtv1					*ft_glob(void);
void					ft_print_error(char *str, t_bool exit_flag);
void					ft_perror(t_bool exit_flag);
void					ft_free_rtv1(t_rtv1 *rtv1);
void					ft_free_var(t_rtv1 *rtv1);
void					ft_init(t_rtv1 *rtv1, int ac, char **av);
void					*ft_create_bad_object(t_rtv1 *rtv1);
float					ft_atof(char *str);
void					ft_run(t_rtv1 *rtv1);

/*
** PROTOTYPES - VECTOR
*/
t_vector				*ft_create_vector(char *str);
void					ft_vector_normalize(t_vector *vector);
float					ft_vector_magnitude(t_vector *vector);
float					ft_vector_square_len(t_vector *vector);
float					ft_vector_dot_mult(t_vector *a, t_vector *b);
t_vector				*ft_moins_vector(t_vector *a, t_vector *b);
t_vector				*ft_mult_vector(t_vector *a, t_vector *b);
t_vector				*ft_mult_num_vector(t_vector *a, int i);
t_vector				*ft_plus_vector(t_vector *a, t_vector *b);
t_vector				*ft_div_vector(t_vector *vector, float val);
float					ft_calc_angle(float rot);
void					ft_rotation(t_vector *vec, t_vector rot);
t_vector				ft_rotation_cylinder_init(void);

/*
** PROTOTYPES - COLOR
*/
t_color					*ft_create_color(char *str);

/*
** PROTOTYPES - CAMERA
*/
void					ft_free_camera(t_rtv1 *rtv1);
void					*ft_create_camera(t_rtv1 *rtv1);
void					ft_init_camera(t_rtv1 *rtv1, void *obj);

/*
** PROTOTYPES - SPHERE
*/
void					ft_free_sphere(t_rtv1 *rtv1);
void					*ft_create_sphere(t_rtv1 *rtv1);
void					ft_init_sphere(t_rtv1 *rtv1, void *obj);
void					ft_search_sphere_hit(t_rtv1 *rtv1, t_sphere *sphere,
						t_ray *ray);
void					ft_lum_hit_sphere(t_rtv1 *rtv1, t_sphere *sphere,
						t_ray *ray, int *blocked);
int						ft_calc_discri_sphere(t_sphere *sphere, t_ray *ray,
						t_hit *tmp);

/*
** PROTOTYPES - PLANE
*/
void					ft_free_plane(t_rtv1 *rtv1);
void					*ft_create_plane(t_rtv1 *rtv1);
void					ft_init_plane(t_rtv1 *rtv1, void *obj);
void					ft_search_plane_hit(t_rtv1 *rtv1, t_plane *plane,
						t_ray *ray);
int						ft_calc_discri_plane(t_plane *plane, t_ray *ray,
						t_hit *tmp);
void					ft_lum_hit_plane(t_rtv1 *rtv1, t_plane *plane,
						t_ray *ray, int *blocked);

/*
** PROTOTYPES - CYLINDER
*/
void					ft_free_cylinder(t_rtv1 *rtv1);
void					*ft_create_cylinder(t_rtv1 *rtv1);
void					ft_init_cylinder(t_rtv1 *rtv1, void *obj);
int						ft_calc_discri_cyl(t_cylinder *cylinder, t_ray *ray,
						t_hit *tmp);
void					ft_search_cylinder_hit(t_rtv1 *rtv1, t_cylinder *cyl,
						t_ray *ray);
void					ft_lum_hit_cyl(t_rtv1 *rtv1, t_cylinder *cyl,
						t_ray *ray, int *blocked);

/*
** PROTOTYPES - CONE
*/
void					ft_free_cone(t_rtv1 *rtv1);
void					*ft_create_cone(t_rtv1 *rtv1);
void					ft_init_cone(t_rtv1 *rtv1, void *obj);
void					ft_search_cone_hit(t_rtv1 *rtv1, t_cone *cone,
						t_ray *ray);
int						ft_calc_discri_cone(t_cone *cone, t_ray *ray,
						t_hit *tmp);
void					ft_lum_hit_cone(t_rtv1 *rtv1, t_cone *cone, t_ray *ray,
						int *blocked);

/*
** PROTOTYPES - LIGHT
*/
void					ft_free_light(t_rtv1 *rtv1);
void					*ft_create_light(t_rtv1 *rtv1);
void					ft_init_light(t_rtv1 *rtv1, void *obj);

/*
** PROTOTYPES - MATERIAL
*/
void					ft_free_material(t_rtv1 *rtv1);
void					*ft_create_material(t_rtv1 *rtv1);
void					ft_init_material(t_rtv1 *rtv1, void *obj);
t_material				*ft_get_material(t_material *material, int i);
void					ft_link_material_object(t_rtv1 *rtv1);

/*
** PROTOTYPES - RAY
*/
void					ft_ray(t_rtv1 *rtv1, t_ray *ray);

/*
** PROTOTYPES - CORE
*/
void					ft_search_hit(t_rtv1 *rtv1, int x, int y, t_ray *ray);
void					ft_copy_hit(t_rtv1 *rtv1, t_hit tmp);
void					ft_calc_lum(t_rtv1 *rtv1, t_pixel *pix);

/*
** PROTOTYPES - SDL
*/
void					ft_create_sdl(t_rtv1 *rtv1);
void					ft_init_sdl(t_rtv1 *rtv1);
void					ft_loop_sdl(t_sdl *sdl);
void					ft_free_sdl(t_rtv1 *rtv1);

#endif

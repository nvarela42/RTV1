# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:37:40 by nvarela           #+#    #+#              #
#    Updated: 2018/03/29 12:03:36 by nvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SYS := $(shell clang -dumpmachine)

CC			=	clang

NAME		=	rtv1

LNAME		=	ft

DIR			=	lib$(LNAME)

HDR			=	$(DIR)/$(DIR).a

SRC			=	main.c									\
				ft_glob.c								\
				ft_print_error.c						\
				ft_perror.c								\
				ft_free_rtv1.c							\
				ft_init.c								\
				ft_free_var.c							\
				ft_create_bad_object.c					\
				ft_atof.c								\
				ft_run.c								\

# CAMERA PART
SRC			+=	camera/ft_create_camera.c				\
				camera/ft_init_camera.c					\
				camera/ft_free_camera.c					\

# SPHERE PART
SRC			+=	sphere/ft_create_sphere.c				\
				sphere/ft_init_sphere.c					\
				sphere/ft_free_sphere.c					\
				sphere/ft_search_sphere_hit.c			\
				sphere/ft_calc_discrimant_sphere.c		\

# PLANE PART
SRC			+=	plane/ft_create_plane.c					\
				plane/ft_init_plane.c					\
				plane/ft_free_plane.c					\
				plane/ft_search_plane_hit.c				\
				plane/ft_calc_discrimant_plane.c		\

# CYLINDER PART
SRC			+=	cylinder/ft_create_cylinder.c			\
				cylinder/ft_init_cylinder.c				\
				cylinder/ft_free_cylinder.c				\
				cylinder/ft_search_cylinder_hit.c		\
				cylinder/ft_calc_discrimant_cyl.c		\

# CONE PART
SRC			+=	cone/ft_create_cone.c					\
				cone/ft_init_cone.c						\
				cone/ft_free_cone.c						\
				cone/ft_search_cone_hit.c				\
				cone/ft_calc_discrimant_cone.c			\

# MATERIAL PART
SRC			+=	material/ft_create_material.c			\
				material/ft_init_material.c				\
				material/ft_free_material.c				\
				material/ft_get_material.c				\
				material/ft_link_material_object.c		\

# LIGHT PART
SRC			+=	light/ft_create_light.c					\
				light/ft_init_light.c					\
				light/ft_free_light.c					\

# VECTOR PART
SRC			+=	vector/ft_create_vector.c				\
				vector/ft_vector_misc.c					\
				vector/ft_calc_on_vector.c				\
				vector/ft_rotation.c					\

# COLOR PART
SRC			+=	color/ft_create_color.c					\

# RAY PART
SRC			+=	ray/ft_ray.c							\

# SDL PART
SRC			+=	sdl/ft_create_sdl.c						\
				sdl/ft_init_sdl.c						\
				sdl/ft_loop_sdl.c						\
				sdl/ft_free_sdl.c						\

# CORE PART
SRC			+=	core/ft_search_hit.c					\
				core/ft_calc_lum.c						\
				core/ft_copy_hit.c						\

OBJ			=	$(patsubst %.c,srcs/%.o,$(SRC))

ifneq (, $(findstring linux, $(SYS)))
LFLAGS		=	-L$(DIR) -l$(LNAME) -lm -lSDL2-2.0
else
LFLAGS		=	-L$(DIR) -l$(LNAME) -framework SDL2
endif

WFLAGS 		=	-Wall -Wextra -Werror

CFLAGS1		=	$(WFLAGS) -I./includes/ -I$(DIR)/includes

OFLAGS		=	 -g

CFLAGS		= 	$(CFLAGS1) $(OFLAGS)

all:		$(HDR) $(NAME)

$(NAME):	$(HDR) $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
			@echo "[\033[32m✔\033[0m] $@"

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $^
		@echo "[\033[32m✔\033[0m] $@"

$(DIR): $(HDR)

$(HDR):
		make -C $(DIR)

clean:
		make -C $(DIR) clean
		rm -f $(OBJ)

fclean:		clean
		make -C $(DIR) fclean
		rm -f $(NAME) $(HDR)

re:			fclean all

.PHONY: all clean fclean re

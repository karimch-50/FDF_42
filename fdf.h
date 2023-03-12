/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:58:40 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 20:07:02 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

/*#######################################################################
#	 							MACROS									#
#######################################################################*/

# define WIDTH  1800
# define HEIGHT 1000
# define ESC 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define PLUS_KEY 69
# define MINUS_KEY 78
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define ON_DESTROY 17
# define P_ISO 34
# define P_ORTHO 31
# define RESET 15
# define ROTATION 91
# define RROTATION 84
# define ISO_ANGLE 60

/*#######################################################################
#	 							STRUCTS									#
#######################################################################*/

typedef struct s_scale
{
	int		right_left;
	int		zome_scale;
	int		up_down;
	int		z_scale;
	float	angle;
}	t_scale;

typedef struct s_line
{
	int		delta_x;
	int		delta_y;
	int		incre_x;
	int		incre_y;
	int		error;
	int		e2;
}	t_line;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_mlx;

typedef struct s_data
{
	t_mlx	mlx;
	t_img	img;
	t_point	point;
	t_line	line;
	t_scale	scale;
	t_point	**coordinates;
	int		x_len;
	int		y_len;
	int		proj;
}	t_data;

/*#######################################################################
#	 						LOAD MAP									#
#######################################################################*/

int		get_width(char *file_name);
int		get_height(char	*file_name);
void	map_checker(char **map, int end);
void	load_map(t_data **data, char *file_name);

/*#######################################################################
#	 					  DEGRADE COLOR									#
#######################################################################*/

int		color_transformer(int i, int distance, t_point p1, t_point p2);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);

/*#######################################################################
#	 					  	  DRAW MAP									#
#######################################################################*/

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	projection_iso(int *x, int *y, int z, int angle);
t_point	prepare_point(t_point point, t_scale scale, int proj);
int		responsive(t_data data, t_scale scale, int *z_scale);
void	draw_line(t_img img, t_point p1, t_point p2);
void	draw_map(t_data	*data);
void	draw_manu(t_data *data);
t_scale	fill_scale(t_data data);

/*#######################################################################
#	 					   EVENTS HANDLER								#
#######################################################################*/

int		key_hook(int key, t_data *data);
t_scale	initial_scale(void);
void	arrow_key(int key, t_scale *scale);
void	rotation_key(int key, t_scale *scale);
int		ft_close(t_data *data);
int		mouse_hook(int key, int x, int y, t_data *data);

/* Error case */
void	print_error(int exit_status, char *msg);

/* free */
void	ft_free_tmp_map(char **str, int end);
void	ft_free(char **str);
void	ft_free_all(t_data *data);

#endif
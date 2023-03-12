/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:57:36 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 17:09:27 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_map(t_data *data, t_scale scale, int res)
{
	mlx_destroy_image(data->mlx.mlx_ptr, data->img.img);
	data->img.img = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bpp, &data->img.line_length, &data->img.endian);
	if (res == 1)
		data->scale = fill_scale(*data);
	else
	{
		data->scale.up_down += scale.up_down;
		data->scale.right_left += scale.right_left;
		data->scale.angle += scale.angle;
		data->scale.z_scale += scale.z_scale;
		data->scale.zome_scale += scale.zome_scale;
	}
	draw_map(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, \
	data->mlx.mlx_win, data->img.img, 0, 0);
	draw_manu(data);
}

void	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img.img);
	ft_free_all(data);
	exit(0);
}

int	key_hook(int key, t_data *data)
{
	t_scale	scale;
	int		res;

	res = 0;
	scale = initial_scale();
	if (key == ESC)
		close_window(data);
	arrow_key(key, &scale);
	rotation_key(key, &scale);
	if (key == PLUS_KEY)
		scale.z_scale = 1;
	else if (key == MINUS_KEY)
		scale.z_scale = -1;
	else if (key == RESET)
		res = 1;
	else if (key == P_ISO)
		data->proj = 1;
	else if (key == P_ORTHO)
		data->proj = 0;
	redraw_map(data, scale, res);
	return (0);
}

int	ft_close(t_data *data)
{
	close_window(data);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_data *data)
{
	t_scale	scale;

	(void) x;
	(void) y;
	scale = initial_scale();
	if (key == SCROLL_UP)
		scale.zome_scale = -1;
	else if (key == SCROLL_DOWN)
		scale.zome_scale = 1;
	redraw_map(data, scale, 0);
	return (0);
}

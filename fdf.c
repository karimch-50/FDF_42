/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:57:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 21:07:23 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook_man(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img);
		ft_free_all(data);
		exit(0);
	}
	return (0);
}

int	ft_close_man(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.mlx_win);
	mlx_destroy_image(data->mlx.mlx_ptr, data->img.img);
	ft_free_all(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		print_error(4, "Error: invalide argument");
	data = malloc(sizeof(t_data));
	if (!data)
		print_error(3, "Error: allocation faild");
	data->mlx.mlx_ptr = mlx_init();
	load_map(&data, argv[1]);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, "fdf");
	data->img.img = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bpp, &data->img.line_length, &data->img.endian);
	data->proj = 1;
	data->scale = fill_scale(*data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, \
	data->mlx.mlx_win, data->img.img, 0, 0);
	mlx_key_hook(data->mlx.mlx_win, &key_hook_man, data);
	mlx_hook(data->mlx.mlx_win, ON_DESTROY, 0, ft_close_man, data);
	mlx_loop(data->mlx.mlx_ptr);
	ft_free_all(data);
	return (0);
}

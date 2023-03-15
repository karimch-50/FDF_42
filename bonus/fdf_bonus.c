/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:58:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/15 18:44:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	static t_data	*data;

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
	draw_manu(data);
	mlx_mouse_hook(data->mlx.mlx_win, &mouse_hook, data);
	mlx_key_hook(data->mlx.mlx_win, &key_hook, data);
	mlx_hook(data->mlx.mlx_win, ON_DESTROY, 0, ft_close, data);
	mlx_loop(data->mlx.mlx_ptr);
	ft_free_all(data);
	return (0);
}

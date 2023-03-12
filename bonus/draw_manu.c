/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:45:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 16:46:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_manu(t_data *data)
{
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 20, 0xFFFFFFF, "BY: KCHAOUKI");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 45, 0xFFFFFFF, "----------------------How to use:\
	----------------------");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 70, 0X00FF00, "Projections=> ISO {press i}, ORTHO {press o}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 95, 0X00FF00, "Altitude=>    increase {press +}, decrease {press -}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 120, 0X00FF00, "Zoom=>        In {scroll up}, Out {scroll down}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 145, 0X00FF00, "Rotation=>    Right {press 2}, Left {press 8}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 170, 0X00FF00, "Directions=>  Left {press <-}, Right {press ->}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	170, 195, 0X00FF00, "Up {press arrow up}, Down {press arrow down}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 220, 0X00FF00, "Reset=>       {press r}");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.mlx_win, \
	30, 245, 0XFF0000, "Exit: ESC");
}

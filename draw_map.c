/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:41:41 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 20:06:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	projection_iso(int *x, int *y, int z, int angle)
{
	(void) angle;
	*x = ((double)*x * cos(angle * M_PI / 180)) - ((double)*y * sin((angle / 2) * M_PI / 180));
	*y = (((((double)*x * sin(angle * M_PI / 180)) + ((double)*y * cos((angle / 2) * M_PI / 180)))) - z) / 2;
}

t_point	prepare_point(t_point point, t_scale scale, int proj)
{
	(void) proj;
	point.x *= scale.zome_scale;
	point.y *= scale.zome_scale;
	point.z *= scale.z_scale;
	if (proj == 1)
		projection_iso(&point.x, &point.y, point.z, scale.angle);
	point.y += scale.up_down;
	point.x += scale.right_left;
	return (point);
}

void	draw_map(t_data	*data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < data->y_len)
	{
		j = -1;
		while (++j < data->x_len)
		{
			if (j + 1 < data->x_len)
				draw_line(data->img, \
				prepare_point(data->coordinates[i][j], \
				data->scale, data->proj), \
				prepare_point(data->coordinates[i][j + 1], \
				data->scale, data->proj));
			if (i + 1 < data->y_len)
				draw_line(data->img, \
				prepare_point(data->coordinates[i][j], \
				data->scale, data->proj), \
				prepare_point(data->coordinates[i + 1][j], \
				data->scale, data->proj));
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:41:41 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/15 18:39:08 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_iso(int *x, int *y, int z, int angle)
{
	*x = ((double)*x * cos(angle * M_PI / 180)) \
	- ((double)*y * sin((angle / 2) * M_PI / 180));
	*y = (((((double)*x * sin(angle * M_PI / 180)) \
	+ ((double)*y * cos((angle / 2) * M_PI / 180)))) - z) / 2;
}

void	ft_rotation(int *x, int *y, t_scale scale, t_data data)
{
	static int	rp_x;
	static int	rp_y;

	if (data.proj)
	{
		rp_x = scale.right_left;
		rp_y = scale.up_down;
	}
	else
	{
		rp_x = scale.right_left / 2;
		rp_y = scale.up_down / 2;
	}	
	*x -= rp_x;
	*y -= rp_y;
	*x = ((double)*x * cos((scale.rotation_angle * M_PI) / 180)) \
	- ((double)*y * sin((scale.rotation_angle * M_PI) / 180));
	*y = ((((double)*x * sin((scale.rotation_angle * M_PI) / 180)) \
	+ ((double)*y * cos((scale.rotation_angle * M_PI) / 180))));
	*x += rp_x;
	*y += rp_y;
}

t_scale	fill_scale(t_data data)
{
	t_scale	scale;

	scale.angle = ISO_ANGLE;
	if (data.x_len == data.y_len)
		scale.right_left = WIDTH / 2;
	else
		scale.right_left = WIDTH / 3;
	scale.up_down = HEIGHT / 5;
	scale.zome_scale = (float)responsive(data, scale, &scale.z_scale) / \
	(float)1.5;
	return (scale);
}

t_point	prepare_point(t_point point, t_scale scale, t_data data)
{
	point.x *= scale.zome_scale;
	point.y *= scale.zome_scale;
	point.z *= scale.z_scale;
	if (data.proj == 1)
	{
		projection_iso(&point.x, &point.y, point.z, scale.angle);
		point.y += scale.up_down;
		point.x += scale.right_left;
	}
	else
	{
		point.y += scale.up_down / 2;
		point.x += scale.right_left / 2;
	}
	ft_rotation(&point.x, &point.y, scale, data);
	return (point);
}

void	draw_map(t_data	*data)
{
	int	i;
	int	j;

	i = ((j = -1), -1);
	if (data->x_len <= 1 && data->y_len <= 1)
		return ;
	while (++i < data->y_len)
	{
		j = -1;
		while (++j < data->x_len)
		{
			if (j + 1 < data->x_len)
				draw_line(data->img, \
				prepare_point(data->coordinates[i][j], \
				data->scale, *data), \
				prepare_point(data->coordinates[i][j + 1], \
				data->scale, *data));
			if (i + 1 < data->y_len)
				draw_line(data->img, \
				prepare_point(data->coordinates[i][j], \
				data->scale, *data), \
				prepare_point(data->coordinates[i + 1][j], \
				data->scale, *data));
		}
	}
}

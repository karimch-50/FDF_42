/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responsive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 07:57:22 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 21:47:56 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_all_points(t_data data, t_scale scale, \
							int zome_scale, int z_scale)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -1;
	while (++i < data.y_len)
	{
		j = -1;
		while (++j < data.x_len)
		{
			x = data.coordinates[i][j].x * zome_scale;
			y = data.coordinates[i][j].y * zome_scale;
			projection_iso(&x, &y, data.coordinates[i][j].z * z_scale, \
			scale.angle);
			if (x + scale.right_left <= 0 || x + scale.right_left >= WIDTH \
			|| y + scale.up_down <= 0 || y + scale.up_down >= HEIGHT)
				return (1);
		}
	}
	return (0);
}

/* puts the shape iside the window by checking all map coordinates */
int	responsive(t_data data, t_scale scale, int *z_scale)
{
	int	zome_scale;

	zome_scale = 1;
	*z_scale = 5;
	while (data.x_len > 1 && data.y_len > 1)
	{
		if (check_all_points(data, scale, zome_scale, 0))
			break ;
		zome_scale += 1;
	}
	zome_scale -= 1;
	while (1)
	{
		if (!check_all_points(data, scale, zome_scale, *z_scale))
			break ;
		(*z_scale) -= 1;
	}
	return (zome_scale);
}

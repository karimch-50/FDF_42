/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle_hooks_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:26:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/14 17:14:48 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_scale	initial_scale(void)
{
	t_scale	scale;

	scale.angle = 0;
	scale.right_left = 0;
	scale.up_down = 0;
	scale.z_scale = 0;
	scale.zome_scale = 0;
	scale.rotat = 0;
	scale.rotation_angle = 0;
	return (scale);
}

void	arrow_key(int key, t_scale *scale)
{
	if (key == ARROW_UP)
		scale->up_down = -20;
	else if (key == ARROW_DOWN)
		scale->up_down = 20;
	else if (key == ARROW_RIGHT)
		scale->right_left = 20;
	else if (key == ARROW_LEFT)
		scale->right_left = -20;
}

void	rotation_key(int key, t_scale *scale)
{
	if (key == ROTATION)
	{
		scale->rotation_angle = 1;
		scale->rotat = 1;
	}
	else if (key == RROTATION)
	{
		scale->rotat = 1;
		scale->rotation_angle = -1;
	}
}

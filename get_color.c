/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:45:11 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 17:03:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_r(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}

int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

int	color_transformer(int i, int distance, t_point p1, t_point p2)
{
	int	red;
	int	green;
	int	blue;

	red = (((float)distance - i) / (float)distance) * get_r(p1.color) \
	+ ((float)i / (float)distance) * get_r(p2.color);
	green = (((float)distance - i) / (float)distance) * get_g(p1.color) \
	+ ((float)i / (float)distance) * get_g(p2.color);
	blue = (((float)distance - i) / (float)distance) * get_b(p1.color) \
	+ ((float)i / (float)distance) * get_b(p2.color);
	return (red << 16 | green << 8 | blue);
}

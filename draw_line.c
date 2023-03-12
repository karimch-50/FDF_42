/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:06:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 08:36:57 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	take_decision(t_line *line, t_point *p1, t_point *p2)
{
	if (line->e2 >= line->delta_y)
	{
		if (p1->x == p2->x)
			return (1);
		line->error += line->delta_y;
		p1->x += line->incre_x;
	}
	else if (line->e2 <= line->delta_x)
	{
		if (p1->y == p2->y)
			return (1);
		line->error += line->delta_x;
		p1->y += line->incre_y;
	}
	return (0);
}

static int	get_distance(t_point p1, t_point p2, t_line line)
{
	int	count;

	count = 0;
	while (1)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
			count++;
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = 2 * line.error;
		if (take_decision(&line, &p1, &p2))
			break ;
	}
	return (count);
}

static void	direction(t_point p1, t_point p2, t_line *line)
{
	if (p1.x < p2.x)
		line->incre_x = 1;
	else
		line->incre_x = -1;
	if (p1.y < p2.y)
		line->incre_y = 1;
	else
		line->incre_y = -1;
}

void	draw_line(t_img img, t_point p1, t_point p2)
{
	t_line	line;
	int		distance;
	int		i;

	line.delta_x = abs(p2.x - p1.x);
	line.delta_y = -abs(p2.y - p1.y);
	direction(p1, p2, &line);
	line.error = line.delta_x + line.delta_y;
	distance = get_distance(p1, p2, line);
	i = 0;
	while (1)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
			my_mlx_pixel_put(&img, p1.x, p1.y, \
			color_transformer(i++, distance, p1, p2));
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = 2 * line.error;
		if (take_decision(&line, &p1, &p2))
			break ;
	}
}

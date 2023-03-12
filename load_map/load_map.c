/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:58:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 21:50:11 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "get_next_line.h"

static int	get_color(char *str)
{
	int	nbr;
	int	n;
	int	i;

	i = 0;
	if (!ft_strchr(str, ','))
		return (16777215);
	while (str[i] != ',')
		i++;
	i += 3;
	nbr = 0;
	while (str[i])
	{
		n = ft_tolower(str[i]);
		if (ft_tolower(str[i]) >= 'a' && ft_tolower(str[i]) <= 'f')
			n -= 'a' - 10;
		else if (str[i] >= '0' && str[i] <= '9')
			n -= '0';
		nbr = nbr * 16 + n;
		i++;
	}
	return (nbr);
}

static char	**fill_map_holder(char *file_name, int size)
{
	char	**output;
	int		fd;
	int		i;

	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		print_error(2, "Error: file discriptor error");
	output = malloc(sizeof(char *) * size);
	if (!output)
		print_error(3, "Error: allocation faild");
	i = 0;
	while (i < size)
		output[i++] = get_next_line(fd, 0);
	close (fd);
	return (output);
}

static void	fill_point(t_point *point, int x, int y, char *str)
{
	point->x = x;
	point->y = y;
	point->z = ft_atoi(str);
	point->color = get_color(str);
}

static t_point	**fill_map_coordinates(char **map_holder, int x_len, int y_len)
{
	t_point	**coordinates;
	char	**split;
	int		i;
	int		j;

	coordinates = malloc(sizeof(t_point) * y_len);
	if (!coordinates)
		print_error(3, "Error: allocation faild");
	i = -1;
	while (++i < y_len)
	{
		coordinates[i] = malloc(sizeof(t_point) * x_len);
		if (!coordinates[i])
			print_error(3, "Error: allocation faild");
		j = -1;
		split = ft_split(map_holder[i], ' ');
		while (++j < x_len)
			fill_point(&coordinates[i][j], j, i, split[j]);
		ft_free(split);
	}
	return (ft_free_tmp_map(map_holder, y_len), coordinates);
}

void	load_map(t_data **data, char *file_name)
{
	char	**map_holder;
	char	*format;

	format = ft_strnstr(file_name, ".fdf", ft_strlen(file_name));
	if (!format || ft_strncmp(format, ".fdf", ft_strlen(format)) != 0)
		print_error(15, "Error: invalide file name");
	(*data)->x_len = get_width(file_name);
	(*data)->y_len = get_height(file_name);
	if ((*data)->x_len == 0 || (*data)->x_len == 0)
		print_error(15, "Error: invalide map");
	map_holder = fill_map_holder(file_name, (*data)->y_len);
	map_checker(map_holder, (*data)->y_len);
	(*data)->coordinates = \
	fill_map_coordinates(map_holder, (*data)->x_len, (*data)->y_len);
}

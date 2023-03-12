/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:18:20 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 16:50:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "get_next_line.h"

int	get_width(char *file_name)
{
	char	*line;
	int		count;
	int		fd;
	int		i;

	i = 0;
	count = 0;
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		print_error(2, "Error: file discriptor error");
	line = get_next_line(fd, 1);
	while (line && line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
			count++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	if (close (fd) == -1)
		print_error(2, "Error: file discriptor error");
	return (free(line), count);
}

int	get_height(char	*file_name)
{
	char	*line;
	int		count;
	int		fd;

	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		print_error(2, "Error: file discriptor error");
	count = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		free(line);
		count++;
	}
	if (close (fd) == -1)
		print_error(2, "Error: file discriptor error");
	return (count);
}

static int	count_split_element(char **split)
{
	int	count;

	count = 0;
	while (split && split[count])
		count++;
	return (count);
}

void	map_checker(char **map, int y_end)
{
	char	**split;
	int		count;
	int		new_count;
	int		i;

	split = ft_split(map[0], ' ');
	count = count_split_element(split);
	ft_free(split);
	i = 1;
	while (i < y_end)
	{
		split = ft_split(map[i], ' ');
		new_count = count_split_element(split);
		ft_free(split);
		if (new_count < count)
		{
			ft_free_tmp_map(map, y_end);
			print_error(6, "Error: invalide map");
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:33:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/12 08:40:39 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_tmp_map(char **str, int end)
{
	int	i;

	i = 0;
	while (i < end)
		free(str[i++]);
	free(str);
}

static void	ft_free_map(t_point **coordinates, int end)
{
	int	i;

	i = -1;
	while (++i < end)
		free(coordinates[i]);
	free(coordinates);
}

void	ft_free_all(t_data *data)
{
	ft_free_map(data->coordinates, data->y_len);
	free(data);
}

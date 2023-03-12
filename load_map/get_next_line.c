/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:55:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/03/02 10:27:55 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static void	ft_read_and_stash(int fd, char **save)
{
	char	*buff;
	char	*tmp;
	int		x;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		(*save) = NULL;
		return ;
	}
	x = 0;
	while ("1337")
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x <= 0)
			break ;
		buff[x] = '\0';
		tmp = (*save);
		(*save) = ft_join(tmp, buff);
		free(tmp);
		if (ft_check_newline(buff))
			break ;
	}
	free(buff);
	return ;
}

// here we are trying to get the line folowed by a \n
static char	*ft_get_line_with_newline(char *str)
{
	char	*output;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	output = malloc(i + 2);
	if (!output)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		output[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

// here we are trying to get any thing after \n 
// and store it on the static var to the next use if it exist of course
static char	*ft_save(char *str)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || (str[i] == '\n' && str[i + 1] == '\0'))
		return (NULL);
	output = malloc(ft_len(str) - i + 1);
	if (!output)
		return (NULL);
	i++;
	while (str[i])
		output[j++] = str[i++];
	output[j] = '\0';
	return (output);
}
//i++ here to do not include \n on returned value

char	*get_next_line(int fd, int free_it)
{
	static char	*save;
	char		*line;
	char		*tmp;

	ft_read_and_stash(fd, &save);
	if (fd == -1 || BUFFER_SIZE <= 0 || !save)
		return (NULL);
	tmp = save;
	line = ft_get_line_with_newline(tmp);
	save = ft_save(tmp);
	free(tmp);
	if (free_it)
	{
		free(save);
		save = NULL;
	}
	return (line);
}

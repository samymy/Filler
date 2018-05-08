/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 11:14:36 by vdubinki          #+#    #+#             */
/*   Updated: 2017/12/29 11:14:38 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int						get_player_number(int fd)
{
	char	*line;
	char	*tmp;

	if (get_next_line(fd, &line) != 1)
		return (1);
	if (!(tmp = ft_strchr(line, 'p')))
	{
		free(line);
		return (1);
	}
	free(line);
	return (*++tmp - '0');
}

static t_dimension		*get_dimension(char *line)
{
	static t_dimension	dimension;

	while (*line != '\0' && !ft_isdigit(*line))
		line++;
	dimension.rows = ft_atoi(line);
	while (*line != '\0' && ft_isdigit(*line))
		line++;
	while (*line != '\0' && !ft_isdigit(*line))
		line++;
	dimension.columns = ft_atoi(line);
	return (&dimension);
}

char					**get_map(int fd)
{
	char			**map;
	t_dimension		*dimension;
	char			*line;
	char			*tmp;
	int				idx;

	if (get_next_line(fd, &line) != 1)
		return (0);
	dimension = get_dimension(line);
	free(line);
	if (!(map = init_array(dimension)))
		return (0);
	if (get_next_line(fd, &line) != 1)
		return (0);
	free(line);
	idx = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strchr(line, ' ');
		ft_strcpy(map[idx], ++tmp);
		free(line);
		if (++idx == dimension->rows)
			break ;
	}
	return (map);
}

char					**get_piece(int fd)
{
	char			**piece;
	t_dimension		*dimension;
	char			*line;
	int				idx;

	if (get_next_line(fd, &line) != 1)
		return (0);
	dimension = get_dimension(line);
	free(line);
	if (!(piece = init_array(dimension)))
		return (0);
	idx = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_strcpy(piece[idx], line);
		free(line);
		if (++idx == dimension->rows)
			break ;
	}
	return (piece);
}

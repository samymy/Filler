/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:09:49 by vdubinki          #+#    #+#             */
/*   Updated: 2018/01/04 12:09:51 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

static int				is_placed(char **map, char **piece, int row, int col)
{
	int		count;
	int		p_row;
	int		p_col;
	int		m_col;

	count = 0;
	p_row = -1;
	while (piece[++p_row])
	{
		p_col = -1;
		m_col = col;
		while (piece[p_row][++p_col])
		{
			if (!map[row] || !map[row][m_col] || (piece[p_row][p_col] == '*' &&
				map[row][m_col] != '.' && map[row][m_col] != g_player))
				return (0);
			if (piece[p_row][p_col] == '*' && map[row][m_col] == g_player)
				count++;
			m_col++;
		}
		row++;
	}
	if (count != 1)
		return (0);
	return (1);
}

static t_dimension		*get_opponent_coord(char **map)
{
	static t_dimension	opponent_coord;
	int					row;
	int					col;

	opponent_coord.rows = 0;
	opponent_coord.columns = 0;
	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
			if (map[row][col] == ft_tolower(g_opponent) ||
				map[row][col] == g_opponent)
			{
				opponent_coord.rows = row;
				opponent_coord.columns = col;
				return (&opponent_coord);
			}
	}
	return (&opponent_coord);
}

static int				get_closeness(t_dimension *opponent_coord,
													int row, int col)
{
	return (ABS(opponent_coord->rows - row) +
			ABS(opponent_coord->columns - col));
}

t_dimension				*get_coordinates(char **map, char **piece)
{
	static t_dimension	coordinates;
	t_dimension			*opponent_coord;
	int					closeness;
	int					row;
	int					col;

	coordinates.rows = 0;
	coordinates.columns = 0;
	opponent_coord = get_opponent_coord(map);
	closeness = 2147483647;
	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
			if (is_placed(map, piece, row, col) &&
				get_closeness(opponent_coord, row, col) <= closeness)
			{
				closeness = get_closeness(opponent_coord, row, col);
				coordinates.rows = row;
				coordinates.columns = col;
			}
	}
	return (&coordinates);
}

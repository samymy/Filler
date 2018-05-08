/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:06:38 by vdubinki          #+#    #+#             */
/*   Updated: 2018/01/04 10:06:40 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

int				main(void)
{
	char		**map;
	char		**piece;
	t_dimension	*coordinates;

	g_player = get_player_number(0) == 1 ? 'O' : 'X';
	g_opponent = g_player == 'O' ? 'X' : 'O';
	while (1)
	{
		if (!(map = get_map(0)))
			break ;
		if (!(piece = get_piece(0)))
			break ;
		coordinates = get_coordinates(map, piece);
		free_array(map);
		free_array(piece);
		ft_putnbr(coordinates->rows);
		ft_putchar(' ');
		ft_putnbr(coordinates->columns);
		ft_putchar('\n');
	}
	return (0);
}

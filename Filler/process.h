/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:09:44 by vdubinki          #+#    #+#             */
/*   Updated: 2018/01/04 12:09:46 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "map.h"
# include "array.h"

# define ABS(x) (((x) < 0) ? (-x) : (x))

char			g_player;

char			g_opponent;

t_dimension		*get_coordinates(char **map, char **piece);

#endif

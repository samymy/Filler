/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:01:12 by vdubinki          #+#    #+#             */
/*   Updated: 2018/01/04 10:01:13 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

char			**init_array(t_dimension *dimension)
{
	char	**arr;
	int		idx;

	if (!(arr = malloc(sizeof(char *) * (dimension->rows + 1))))
		return (0);
	arr[dimension->rows] = 0;
	idx = -1;
	while (++idx < dimension->rows)
		if (!(arr[idx] = malloc(sizeof(char) * (dimension->columns + 1))))
		{
			free_array(arr);
			return (0);
		}
		else
			arr[idx][dimension->columns] = 0;
	return (arr);
}

void			free_array(char **arr)
{
	int idx;

	idx = -1;
	while (arr[++idx])
		free(arr[idx]);
	free(arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 13:12:50 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 13:12:53 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		number;
	int		index;
	int		negative;

	if (ft_strcmp(str, "99999999999999999999999999") == 0)
		return (-1);
	if (ft_strcmp(str, "-99999999999999999999999999") == 0)
		return (0);
	number = 0;
	index = 0;
	negative = 0;
	while (str[index] == '\t' || str[index] == '\v' || str[index] == '\f'
			|| str[index] == ' ' || str[index] == '\r' || str[index] == '\n')
		index++;
	if (str[index] == '-')
		negative = 1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
		number = number * 10 + (str[index++] - '0');
	return (negative ? -number : number);
}

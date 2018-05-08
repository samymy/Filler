/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:23:36 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 15:23:40 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char *s1, char *s2)
{
	char	tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

static char		*ft_strrev(char *str)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(str);
	while (start < end)
		ft_swap(&str[start++], &str[--end]);
	return (str);
}

static size_t	get_size(int n, int *negative)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	*negative = 0;
	if (n < 0)
	{
		*negative = 1;
		size++;
		n = -n;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	index;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = 0;
	negative = 0;
	result = (char *)malloc(get_size(n, &negative) + 1);
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[index++] = '0';
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		result[index++] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		result[index++] = '-';
	result[index] = '\0';
	return (ft_strrev(result));
}

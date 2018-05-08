/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:08:17 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 12:08:20 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char *str, char *to_find, size_t len)
{
	size_t index_str;
	size_t index_find;
	size_t index_temp;

	index_str = 0;
	while (index_str < len && str[index_str] != '\0')
	{
		index_find = 0;
		index_temp = index_str;
		while (index_find < ft_strlen(to_find) && index_temp < len &&
												str[index_temp] != '\0')
			if (str[index_temp++] != to_find[index_find++])
				break ;
			else
			{
				if (index_find == ft_strlen(to_find))
					return (index_str);
			}
		index_str++;
	}
	return (-1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	index;
	int	i;

	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	index = get_index((char *)haystack, (char *)needle, len);
	i = 0;
	if (index != -1)
	{
		while (i++ < index)
			haystack++;
		return ((char *)haystack);
	}
	return (NULL);
}

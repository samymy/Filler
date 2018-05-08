/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 11:25:03 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 11:25:06 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		index;

	index = ft_strlen(s);
	while (index != 0)
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index--;
	}
	if (s[index] == (char)c)
		return ((char *)&s[index]);
	return (NULL);
}

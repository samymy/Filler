/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:00:21 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 14:00:24 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cpy;
	size_t	index;

	cpy = s1;
	index = 0;
	while (*cpy != '\0')
		cpy++;
	while (index++ < n && *s2 != '\0')
	{
		*cpy++ = *s2++;
	}
	*cpy = '\0';
	return (s1);
}

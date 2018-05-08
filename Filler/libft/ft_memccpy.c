/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:07:54 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 12:07:57 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	if (n == 0 || s1 == s2)
		return (NULL);
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (n--)
	{
		*dest = *src;
		if (*dest == (unsigned char)c)
			return (++dest);
		dest++;
		src++;
	}
	return (NULL);
}

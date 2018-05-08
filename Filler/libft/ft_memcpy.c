/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:06:50 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 12:06:55 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;

	if (n == 0 || s1 == s2)
		return (s1);
	dest = (char *)s1;
	src = (char *)s2;
	while (n--)
		*dest++ = *src++;
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:08:57 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 12:08:59 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*dest;
	char	*src;

	if (n == 0 || s1 == s2)
		return (s1);
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	dest = (char *)s1;
	src = (char *)s2;
	while (n--)
		dest[n] = src[n];
	return (s1);
}

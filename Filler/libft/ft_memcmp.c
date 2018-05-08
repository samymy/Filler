/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:11:14 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 12:11:17 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;

	if (n == 0)
		return (0);
	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	while (--n && *s1_cpy == *s2_cpy)
	{
		s1_cpy++;
		s2_cpy++;
	}
	return (*s1_cpy - *s2_cpy);
}

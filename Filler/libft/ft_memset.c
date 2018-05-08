/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:03:11 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 12:03:22 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;

	if (len == 0)
		return (b);
	b_cpy = (unsigned char *)b;
	while (len--)
		*b_cpy++ = (unsigned char)c;
	return (b);
}

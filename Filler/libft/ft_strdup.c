/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:20:59 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/27 12:21:01 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*src_cpy;
	char	*temp;

	src_cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (src_cpy == NULL)
		return (NULL);
	temp = src_cpy;
	while (*s1 != '\0')
		*temp++ = *s1++;
	*temp = '\0';
	return (src_cpy);
}

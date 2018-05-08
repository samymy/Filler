/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:20:18 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 15:20:21 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	concat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (concat == NULL)
		return (NULL);
	ft_strcpy(concat, s1);
	ft_strcat(concat, s2);
	return (concat);
}

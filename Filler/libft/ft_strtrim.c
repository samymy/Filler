/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:21:30 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 15:21:32 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ? 1 : 0);
}

static size_t	ft_ws_count(char const *s)
{
	size_t	count;
	size_t	index;
	size_t	len;

	count = 0;
	index = 0;
	len = ft_strlen(s);
	while (ft_iswhitespace(s[index++]))
		count++;
	if (index > len)
		return (count);
	index = len;
	while (ft_iswhitespace(s[--index]))
		count++;
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*trimmed;
	size_t	ws_count;
	size_t	len;
	size_t	index;

	if (!s)
		return (NULL);
	ws_count = ft_ws_count(s);
	len = ft_strlen(s);
	if (ws_count == 0)
	{
		trimmed = (char *)malloc(sizeof(char) * (len + 1));
		return (trimmed ? ft_strcpy(trimmed, s) : NULL);
	}
	index = 0;
	while (ft_iswhitespace(s[index]))
		index++;
	trimmed = (char *)malloc(sizeof(char) * (len - ws_count + 1));
	return (trimmed ? ft_strsub(s, index, len - ws_count) : NULL);
}

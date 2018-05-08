/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:01:29 by vdubinki          #+#    #+#             */
/*   Updated: 2017/11/08 11:01:31 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		put(char **line, char **buff)
{
	char	*nl;
	char	*tmp;

	if (!buff)
		return (0);
	if (!(nl = ft_strchr(*buff, '\n')))
		return (0);
	if (!(tmp = malloc(sizeof(char) * (ft_strlen(nl + 1) + 1))))
		return (-1);
	ft_strcpy(tmp, nl + 1);
	*nl = '\0';
	if (!(*line = ft_strdup(*buff)))
		return (-1);
	free(*buff);
	*buff = tmp;
	return (1);
}

static int		concat(char **buff, char *tmp_buff)
{
	char	*tmp;

	if (!(*buff))
	{
		if (!(*buff = ft_strdup(tmp_buff)))
			return (0);
		return (1);
	}
	tmp = *buff;
	*buff = ft_strjoin(tmp, tmp_buff);
	free(tmp);
	if (!(*buff))
		return (0);
	return (1);
}

static int		get_rest(char **line, char **buff)
{
	if (ft_strlen(*buff) != 0)
	{
		if (!(*line = ft_strdup(*buff)))
			return (-1);
		free(*buff);
		*buff = 0;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buff;
	char			tmp[BUFF_SIZE + 1];
	int				rb;

	if (!buff)
		buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if ((rb = put(line, &buff)) != 0)
		return (rb);
	while ((rb = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[rb] = '\0';
		if (!concat(&buff, tmp))
			return (-1);
		if (ft_strchr(tmp, '\n'))
			return (put(line, &buff));
	}
	if (rb == -1)
		return (-1);
	if ((rb = get_rest(line, &buff)) != 0)
		return (rb);
	if (!buff)
		free(buff);
	return (0);
}

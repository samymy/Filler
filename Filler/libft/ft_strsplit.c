/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdubinki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:22:25 by vdubinki          #+#    #+#             */
/*   Updated: 2017/10/31 15:22:27 by vdubinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_words_count(char const *str, char delimiter)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == delimiter && str[i] != '\0')
			i++;
		if (str[i] != delimiter && str[i] != '\0')
		{
			count++;
			while (str[i] != delimiter && str[i] != '\0')
				i++;
		}
	}
	return (++count);
}

static char		*get_word(char const *str, int index, char delimiter)
{
	int		i;
	char	*word;
	int		len;

	i = index;
	len = 0;
	while (str[index] != delimiter && str[i] != '\0')
	{
		len++;
		i++;
	}
	i = 0;
	if (!(word = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[index] != delimiter && str[index] != '\0')
		word[i++] = str[index++];
	word[i] = '\0';
	return (word);
}

static void		free_memory(char **words, int words_count)
{
	int index;

	index = 0;
	while (index < words_count)
		free(words[index]);
	free(words);
}

static char		**get_words(char const *s, int count, char c)
{
	char	**words;
	char	*word;
	int		i;
	int		j;

	if (!(words = (char **)malloc(sizeof(char *) * count)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count - 1)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		if (!(word = get_word(s, j, c)))
		{
			free_memory(words, i);
			return (NULL);
		}
		words[i] = word;
		while (s[j] != c && s[j] != '\0')
			j++;
		j++;
	}
	words[count - 1] = 0;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;

	if (!s)
		return (NULL);
	words = get_words_count(s, c);
	return (get_words(s, words, c));
}

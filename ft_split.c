/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:33:49 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/12 15:46:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **split, size_t i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = true;
			count++;
		}
		else if (*s == c)
			in_word = false;
		s++;
	}
	return (count);
}

static char	*get_next_word(char const **s, char c)
{
	char	*word;
	size_t	len;

	while (**s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = ft_substr(*s, 0, len);
	*s += len;
	return (word);
}

/**
 * @fn char **ft_split(char const *s, char c)
 * @brief Splits a string using a delimiter character.
 * @details Allocates and returns an array of strings obtained by splitting 's'
 * using the character 'c' as a delimiter. The array ends with a NULL pointer.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return  The array of new strings resulting from the split, or NULL if
 * allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n_words;
	size_t	i;

	if (!s)
		return (NULL);
	n_words = count_words(s, c);
	split = malloc(sizeof(char *) * (n_words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < n_words)
	{
		split[i] = get_next_word(&s, c);
		if (!split[i])
			return (free_split(split, i));
		i++;
	}
	split[n_words] = NULL;
	return (split);
}

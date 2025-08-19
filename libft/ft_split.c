/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:49:44 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/05 03:32:04 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char c, char delim)
{
	return (c == delim);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_delim(*s, c) && !in_word)
		{
			in_word = 1;
			count ++;
		}
		else if (is_delim(*s, c))
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && !is_delim(s[len], c))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	free_all(char **arr, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!is_delim(*s, c))
		{
			result[i] = malloc_word(s, c);
			if (!result[i])
				return (free_all(result, i), NULL);
			i++;
			while (*s && !is_delim(*s, c))
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

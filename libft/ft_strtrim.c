/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:55:28 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/07 02:08:07 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	find_end(char const *s1, char const *set)
{
	size_t	end;

	end = 0;
	while (s1[end])
		end++;
	if (end > 0)
		end--;
	while (end > 0 && is_in_set(s1[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end >= start)
		len = end - start + 1;
	else
		len = 0;
	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimmed)
		return (NULL);
	if (len > 0)
		ft_strlcpy(trimmed, &s1[start], len + 1);
	else
		trimmed[0] = '\0';
	return (trimmed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:39:32 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/05 03:35:26 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == '\0')
	{
		return ((char *)s + ft_strlen(s));
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

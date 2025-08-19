/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:40:29 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/07 01:19:24 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char		*last_occurrence;
	unsigned char	ch;

	ch = (unsigned char)c;
	last_occurrence = NULL;
	while (*str)
	{
		if (*str == ch)
		{
			last_occurrence = str;
		}
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return ((char *)last_occurrence);
}

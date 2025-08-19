/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:31:15 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/11 01:47:01 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		i;
	int			neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(count_digits(n) + 1);
	if (!result)
		return (NULL);
	i = 0;
	neg = (n < 0);
	if (neg)
		n = -n;
	while (n > 0)
	{
		result[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}

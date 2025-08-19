/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:31:29 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/10 23:27:42 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr++ = 0;
	}
}

#include <stdio.h>

int main(void)
{
	int i = 0;
	char str[100];
	ft_bzero(str, 30);
	while(i < 30)
	{
		printf("str[%d] = %d \n",i,str[i]);
		i++;
	}
}
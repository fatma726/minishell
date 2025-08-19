/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimaalkaff <fatimaalkaff@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:58:41 by fatimaalkaf       #+#    #+#             */
/*   Updated: 2025/01/11 15:12:28 by fatimaalkaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;
	size_t			i;

	if (len == 0 || dst == src)
		return (dst);
	ptr_src = (unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	i = 0;
	if (ptr_dst > ptr_src)
	{
		while (len-- > 0)
			ptr_dst[len] = ptr_src[len];
	}
	else
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (dst);
}

#include <stdio.h>

int main(void)
{
	
	char buffer[50] = "hello my name  is fatima";
	ft_memmove(buffer + 7, buffer, 5);
	buffer[7 + 5] = '\0';
	printf("%s",(buffer));

}
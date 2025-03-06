/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:42:40 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/14 16:42:42 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ustr;
	unsigned char	uc;
	size_t			i;

	i = 0;
	ustr = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (ustr[i] == uc)
			return ((void *) &ustr[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char *str = "mario";
    char *strr = "mario";
    int c = 95;
    ft_memchr(str, c, 3);
    memchr(strr, c, 3);
    return (0);
}*/

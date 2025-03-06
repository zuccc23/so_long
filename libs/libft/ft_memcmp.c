/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:43:06 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/14 16:43:09 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return ((unsigned char) us1[i] - (unsigned char) us2[i]);
		i++;
	}
	return (0);
}
/*
int main (void)
{
    char *str = "mario";
    char *strr = "";
    size_t c = 2;
    printf("%d\n", ft_memcmp(str, strr, c));
    printf("%d\n", memcmp(str, strr, c));
    return (0);
}*/

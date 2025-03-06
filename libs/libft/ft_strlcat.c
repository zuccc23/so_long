/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:46:37 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/14 16:46:45 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t			i;
	size_t			j;
	size_t			l_src;
	size_t			l_dest;

	i = ft_strlen(dest);
	j = 0;
	l_src = ft_strlen(src);
	l_dest = ft_strlen(dest);
	if (dstsize < 1)
		return (l_src + dstsize);
	while (src[j] && i < dstsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (dstsize < l_dest)
		return (l_src + dstsize);
	else
		return (l_dest + l_src);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	(void)ac;
	char *str = "hello";
	char *strr = "mario";
	size_t c = 4;
	printf("%s\n", str);
	printf("%zu\n", ft_strlcat(str, strr, c));
	//printf("%zu\n", strlcat(str, strr, c));
	return (0);
}*/

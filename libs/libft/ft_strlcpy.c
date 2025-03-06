/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:27:29 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/18 12:20:31 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*int	main(void)
{
	//int c = 'e';
	size_t n = 10;
	char str[11] = "hellooo";
	char strr[] = "worlds";
	char str2[11] = "hellooo";
	char strr2[] = "worlds";
	//char *res = memchr(str, c, n);
	//memchr(str, c, n);
	//ft_strlcat(str, strr, n);
	//printf("%s\n", str);
	printf("%zu\n", ft_strlcpy(str2, strr2, 6));
	printf("%s\n", str2);
	printf("%zu\n", strlcpy(str, strr, 6));
	printf("%s\n", str);
}*/

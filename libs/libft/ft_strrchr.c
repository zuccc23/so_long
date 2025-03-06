/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:50:09 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/18 12:37:52 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*t;
	unsigned char	u_c;

	u_c = (unsigned char)c;
	t = NULL;
	while (*s)
	{
		if (*s == u_c)
			t = (char *)s;
		s++;
	}
	if (u_c == '\0')
		return ((char *)s);
	return (t);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int c = 'j';
	char str[] = "Hello";
	char strr[] = "Hello";
	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(strr, c));
	return (0);
}*/

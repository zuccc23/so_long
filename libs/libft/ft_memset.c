/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:44:15 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/14 16:44:20 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uchar;
	size_t			i;

	uchar = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		uchar[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int	main(int ac, char **av)
{
	(void)ac;
	int c = 40;
	char str[] = "Hellowd";
	char strr[] = "Hellowd";
	ft_memset(str, c, 90);
	memset(strr, c, 90);
	printf("%s\n", str);
	printf("%s\n", strr);
}*/

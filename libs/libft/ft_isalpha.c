/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:01 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/14 16:40:04 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n",ft_isalpha(atoi(av[1])));
	printf("%d\n",isalpha(atoi(av[1])));
	printf("%d\n",ft_isalpha(97));
	printf("%d\n",isalpha(97));
	return (0);
}*/

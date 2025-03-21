/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:54:23 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/18 10:53:22 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	n;

	n = 0;
	while (s[n] && fd >= 0)
	{
		write(fd, &s[n], 1);
		n ++;
	}
	write(fd, "\n", 1);
}

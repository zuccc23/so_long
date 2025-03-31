/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:35:13 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 12:21:16 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *temp, int fd)
{
	char	*buffer;
	int		nb_read;
	char	*cache;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!temp)
		temp = ft_strdup2("");
	nb_read = 1;
	while (nb_read > 0 && check(temp, '\n') != 1)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
			return (free(temp), free(buffer), temp = NULL, NULL);
		buffer[nb_read] = '\0';
		cache = ft_strjoin(temp, buffer);
		if (!cache)
			return (free(temp), free(buffer), NULL);
		free(temp);
		temp = cache;
	}
	free(buffer);
	return (temp);
}

char	*divide_line(char **temp)
{
	char	*res;
	char	*cache;
	int		n;

	if (!*temp || !**temp)
		return (NULL);
	n = 0;
	while ((*temp)[n] != '\n' && (*temp)[n] != '\0')
		n++;
	if ((*temp)[n] == '\n')
		res = ft_substr(*temp, 0, n + 1);
	else
		res = ft_substr(*temp, 0, n);
	if (!res)
		return (free(*temp), *temp = NULL, NULL);
	if ((*temp)[n] == '\n')
		cache = ft_strdup2(*temp + (n + 1));
	else
		cache = ft_strdup2("");
	if (!cache)
		return (free(res), free(*temp), *temp = NULL, NULL);
	free(*temp);
	*temp = cache;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*res;

	if (fd == -1)
		free(temp);
	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line(temp, fd);
	if (!temp)
		return (NULL);
	if (!*temp)
		return (free(temp), temp = NULL, NULL);
	res = divide_line(&temp);
	return (res);
}

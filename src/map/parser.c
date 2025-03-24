/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:01 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/24 15:53:17 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	init_map(t_map **map, char *mapfile, int fd)
{
	fd = -1;
	
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (1);
	
	if (count_height(&(*map), mapfile, &fd) != 0)
		return (1);
	// (*map)->height = 5;
	
	(*map)->grid = malloc(((*map)->height + 1) * sizeof(char *));
	if (!(*map)->grid)
		return (1);
		
	if (fill_map(&(*map), mapfile, &fd) != 0)
		return (1);
	
	if (count_width((*map)->grid, &(*map)) != 0)
		return (1);
	
	return (0);
}

int	count_height(t_map **map, char *mapfile, int *fd)
{
	int		count;
	char	buffer[10];
	char		*temp;

	count = 0;
	*fd = open(mapfile, O_RDONLY);
	if (*fd == -1)
		return (1);
	temp = get_next_line(*fd);
	while (temp != NULL)
	{
		free(temp);
		count++;
		temp = get_next_line(*fd);
	}
	temp = NULL;
	close(*fd);
	*fd = -1;
	if (count < 3)
		return (1);
	(*map)->height = count;
	return (0);
}

int	count_width(char **strs, t_map **map)
{
	int	i;
	int	count;
	int	count_temp;

	i = 1;
	count_temp = 0;
	count = ft_strlen(strs[0]);
	if (count < 5)
		return (1);
	while (strs[i])
	{
		count_temp = ft_strlen(strs[i]);
		if (count != count_temp)
			return (1);
		i++;
	}
	(*map)->width = count;
	return (0);
}

int	fill_map(t_map **map, char *mapfile, int *fd)
{
	int	i;

	i = 0;
	*fd = open(mapfile, O_RDONLY);
	if (*fd == -1)
		return (1);
	while (i < (*map)->height)
	{
		(*map)->grid[i] = get_next_line(*fd);
		if (!(*map)->grid[i])
			return (1);
		remove_nline((*map)->grid[i]);
		i++;
	}
	(*map)->grid[i] = NULL;
	get_next_line(-1);
	close(*fd);
	*fd = -1;
	return (0);
}

void	remove_nline(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

void	strs_print(char **strs) //delete later
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i] != NULL)
	{
		while (strs[i][j])
		{
			write (1, &strs[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
		j = 0;
	}
	// if (strs[i] == NULL)
	// 	write (1, "null", 4);
}

char	*ft_strnoline(const char *s1)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:01 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 11:53:01 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	init_map(t_map **map, char *mapfile)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (ER_MALLOC);
	(*map)->grid = NULL;
	(*map)->fd = -1;
	if (count_height(&(*map), mapfile) != 0)
		return (ER_MAP_SIZE);
	(*map)->grid = malloc(((*map)->height + 1) * sizeof(char *));
	if (!(*map)->grid)
		return (ER_MALLOC);
	if (fill_map(&(*map), mapfile) != 0)
		return (ER_MALLOC);
	if (count_width((*map)->grid, &(*map)) != 0)
		return (ER_MAP_SIZE);
	return (ER_OK);
}

int	count_height(t_map **map, char *mapfile)
{
	int		count;
	char	buffer[10];
	char	*temp;

	count = 0;
	(*map)->fd = open(mapfile, O_RDONLY);
	if ((*map)->fd == -1)
		return (1);
	temp = get_next_line((*map)->fd);
	while (temp != NULL)
	{
		free(temp);
		count++;
		temp = get_next_line((*map)->fd);
	}
	temp = NULL;
	close((*map)->fd);
	(*map)->fd = -1;
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

int	fill_map(t_map **map, char *mapfile)
{
	int	i;

	i = 0;
	(*map)->fd = open(mapfile, O_RDONLY);
	if ((*map)->fd == -1)
		return (1);
	while (i < (*map)->height)
	{
		(*map)->grid[i] = get_next_line((*map)->fd);
		if (!(*map)->grid[i])
			return (1);
		remove_nline((*map)->grid[i]);
		i++;
	}
	(*map)->grid[i] = NULL;
	get_next_line(-1);
	close((*map)->fd);
	(*map)->fd = -1;
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


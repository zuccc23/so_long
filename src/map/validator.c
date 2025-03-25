/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:22:37 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/25 16:21:37 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	valid_map(t_map *map)
{
	int	err_code;

	if (valid_characters(map) != 0)
		return (ER_CHAR);
	if (valid_walls(map) != 0)
		return (ER_WALLS);
	err_code = valid_sprites(map);
	if (err_code != 0)
		return (err_code);
	return (ER_OK);
}

int	valid_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ok_char(map->grid[i][j]) != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ok_char(char c)
{
	if (c == '1')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'P')
		return (0);
	else
		return (1);
}

int	valid_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		if (valid_line(map->grid[i], i, map->height, map->width) != 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	valid_line(char *str, int i, int height, int width)
{
	int	j;

	j = 0;
	if (i == 0 || i == height - 1)
	{
		while (str[j])
		{
			if (str[j] != '1')
				return (1);
			j++;
		}
	}
	else
	{
		if (str[0] != '1' || str[width - 1] != '1')
		{
			return (1);
		}
	}
	return (0);
}

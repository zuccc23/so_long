/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:38:46 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/29 14:34:07 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	valid_sprites(t_map *map)
{
	if (valid_collect(map, 'C') != 0)
		return (ER_COLLECT);
	if (valid_exit_player(map, 'E') != 0)
		return (ER_EXIT);
	if (valid_exit_player(map, 'P') != 0)
		return (ER_PLAYER);
	return (ER_OK);
}

int	valid_exit_player(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (c == map->grid[i][j])
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	valid_collect(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (c == map->grid[i][j])
				count++;
			j++;
		}
		i++;
	}
	if (count < 1)
		return (1);
	map->collect_count = count;
	return (0);
}

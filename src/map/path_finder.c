/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:25:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 11:52:45 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include "../../includes/so_long.h"

// int	path_finder(t_map *map)
// {
// 	t_point	size;
// 	t_point	begin;
// 	char	**tab;

// 	tab = copy_tab(map);
// 	if (!tab)
// 		return (ER_MALLOC);
// 	get_start(&size, &begin, map);
// 	flood_fill(tab, size, begin);
// 	if (correct_path(tab) != 0)
// 	{
// 		free_strs(tab);
// 		return (ER_PATH);
// 	}
// 	free_strs(tab);
// 	tab = copy_tab(map);
// 	if (!tab)
// 		return (ER_MALLOC);
// 	flood_fill_exit(tab, size, begin);
// 	if (correct_path_exit(tab) != 0)
// 	{
// 		free_strs(tab);
// 		return (ER_PATH);
// 	}
// 	free_strs(tab);
// 	return (ER_OK);
// }

void	get_start(t_point *size, t_point *begin, t_map *map)
{
	int	j;
	int	i;

	size->x = map->width;
	size->y = map->height;
	i = 0;
	j = 0;
	while (map->grid[i] && map->grid[i][j] != 'P')
	{
		i++;
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != 'P')
			j++;
	}
	begin->x = j;
	begin->y = i;
}

char	**copy_tab(t_map *map)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (map->height + 1));
	if (!res)
		return (NULL);
	while (map->grid[i])
	{
		res[i] = ft_strdup(map->grid[i]);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	correct_path(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	correct_path_exit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	path_finder(t_map *map)
{
	t_point	size;
	t_point	begin;
	char	**tab;
	int		result;

	get_start(&size, &begin, map);
	tab = copy_tab(map);
	if (!tab)
		return (ER_MALLOC);
	flood_fill(tab, size, begin);
	result = correct_path(tab);
	free_strs(tab);
	if (result != 0)
		return (ER_PATH);
	tab = copy_tab(map);
	if (!tab)
		return (ER_MALLOC);
	flood_fill_exit(tab, size, begin);
	result = correct_path_exit(tab);
	free_strs(tab);
	if (result != 0)
		return (ER_PATH);
	return (ER_OK);
}

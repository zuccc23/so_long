/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:25:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/27 15:21:26 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

void	fill(char **tab, t_point size, t_point begin, char to_fill)
{
	if (char_to_fill(tab[begin.y][begin.x], size, begin) != 0)
		return;
	// ft_printf("test: %c\n", tab[begin.y][begin.x]);
	tab[begin.y][begin.x] = 'F';
	fill(tab, size, (t_point) {.x= begin.x + 1, .y= begin.y}, to_fill);
	fill(tab, size, (t_point) {.x= begin.x - 1, .y= begin.y}, to_fill);
	fill(tab, size, (t_point) {.x= begin.x, .y= begin.y  + 1}, to_fill);
	fill(tab, size, (t_point) {.x= begin.x, .y= begin.y  - 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

int	path_finder(t_map *map)
{
	t_point	size;
	t_point	begin;

	get_start(&size, &begin, map);
	flood_fill(map->grid, size, begin);
	strs_print(map->grid);
	// ft_printf("%d %d ", begin.x, begin.y);
	return (ER_OK);
}

int	char_to_fill(char c, t_point size, t_point begin)
{
	if ((begin.x < 0) || (begin.y < 0))
		return (1);
	if ((begin.x >= size.x) || (begin.y >= size.y))
		return (1);
	if (c == 'P')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == '0')
		return (0);
	else
		return (1);
}

void	get_start(t_point *size, t_point *begin, t_map *map)
{
	int	j;
	int	i;
	
	size->x = map->width;
	size->y = map->height;
	i = 0;
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

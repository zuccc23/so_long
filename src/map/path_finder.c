/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:25:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/25 18:19:03 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

void	fill(char **tab, t_point size, t_point begin, char to_fill)
{
	if ((begin.x < 0) || (begin.y < 0) || (begin.x >= size.x) || (begin.y >= size.y) || to_fillc(tab[begin.y][begin.x], size, begin) == 1)
		return;
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
	//
	return (ER_OK);
}

int	to_fillc(char c, t_point size, t_point begin)
{
	if (c == 'P')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'C')
		return (0);
	// else if ((begin.x < 0) || (begin.y < 0))
	// 	return (1);
	// else if ((begin.x >= size.x) || (begin.y >= size.y))
	// 	return (1);
	else
		return (0);
}

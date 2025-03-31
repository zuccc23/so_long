/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:39:29 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 12:00:04 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include "../../includes/so_long.h"

void	fill_exit(char **tab, t_point size, t_point begin)
{
	if (char_to_fill_exit(tab[begin.y][begin.x], size, begin) != 0)
		return ;
	tab[begin.y][begin.x] = 'F';
	fill_exit(tab, size, (t_point){.x = begin.x + 1, .y = begin.y});
	fill_exit(tab, size, (t_point){.x = begin.x - 1, .y = begin.y});
	fill_exit(tab, size, (t_point){.x = begin.x, .y = begin.y + 1});
	fill_exit(tab, size, (t_point){.x = begin.x, .y = begin.y - 1});
}

void	flood_fill_exit(char **tab, t_point size, t_point begin)
{
	fill_exit(tab, size, begin);
}

int	char_to_fill_exit(char c, t_point size, t_point begin)
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

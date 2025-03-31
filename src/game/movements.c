/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:11:27 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 14:47:11 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/graphics.h"

void	move_up(t_data *data, int *count)
{
	char	**grid;
	int		i;
	int		j;

	ft_printf("Movements : %d\n", ++(*count));
	grid = data->map->grid;
	i = 0;
	j = 0;
	while (grid[i] && grid[i][j] != 'P')
	{
		i++;
		j = 0;
		while (grid[i][j] && grid[i][j] != 'P')
			j++;
	}
	if (grid[i - 1][j] == '1')
		return ;
	if (grid[i - 1][j] == 'C')
		data->map->collect_count--;
	if (grid[i - 1][j] == 'E' && data->map->collect_count == 0)
		close_window(data);
	if (grid[i - 1][j] == 'E' && data->map->collect_count > 0)
		return ;
	grid[i - 1][j] = 'P';
	grid[i][j] = '0';
}

void	move_down(t_data *data, int *count)
{
	char	**grid;
	int		i;
	int		j;

	ft_printf("Movements : %d\n", ++(*count));
	grid = data->map->grid;
	i = 0;
	j = 0;
	while (grid[i] && grid[i][j] != 'P')
	{
		i++;
		j = 0;
		while (grid[i][j] && grid[i][j] != 'P')
			j++;
	}
	if (grid[i + 1][j] == '1')
		return ;
	if (grid[i + 1][j] == 'C')
		data->map->collect_count--;
	if (grid[i + 1][j] == 'E' && data->map->collect_count == 0)
		close_window(data);
	if (grid[i + 1][j] == 'E' && data->map->collect_count > 0)
		return ;
	grid[i + 1][j] = 'P';
	grid[i][j] = '0';
}

void	move_left(t_data *data, int *count)
{
	char	**grid;
	int		i;
	int		j;

	ft_printf("Movements : %d\n", ++(*count));
	grid = data->map->grid;
	i = 0;
	j = 0;
	while (grid[i] && grid[i][j] != 'P')
	{
		i++;
		j = 0;
		while (grid[i][j] && grid[i][j] != 'P')
			j++;
	}
	if (grid[i][j - 1] == '1')
		return ;
	if (grid[i][j - 1] == 'C')
		data->map->collect_count--;
	if (grid[i][j - 1] == 'E' && data->map->collect_count == 0)
		close_window(data);
	if (grid[i][j - 1] == 'E' && data->map->collect_count > 0)
		return ;
	grid[i][j - 1] = 'P';
	grid[i][j] = '0';
}

void	move_right(t_data *data, int *count)
{
	char	**grid;
	int		i;
	int		j;

	ft_printf("Movements : %d\n", ++(*count));
	grid = data->map->grid;
	i = 0;
	j = 0;
	while (grid[i] && grid[i][j] != 'P')
	{
		i++;
		j = 0;
		while (grid[i][j] && grid[i][j] != 'P')
			j++;
	}
	if (grid[i][j + 1] == '1')
		return ;
	if (grid[i][j + 1] == 'C')
		data->map->collect_count--;
	if (grid[i][j + 1] == 'E' && data->map->collect_count == 0)
		close_window(data);
	if (grid[i][j + 1] == 'E' && data->map->collect_count > 0)
		return ;
	grid[i][j + 1] = 'P';
	grid[i][j] = '0';
}

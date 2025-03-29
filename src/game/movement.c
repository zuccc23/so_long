/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:43:09 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/29 15:16:12 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/graphics.h"

int	key_handler(int keycode, t_data *vars, t_map *map)
{
	//add movement count
	if (keycode == XK_w)
	{
		ft_printf("up!\n");
		move_up(vars);
	}
	if (keycode == XK_a)
	{
		ft_printf("left!\n");
		move_left(vars);
	}
	if (keycode == XK_s)
	{
		ft_printf("down!\n");
		move_down(vars);
	}
	if (keycode == XK_d)
	{
		ft_printf("right!\n");
		move_right(vars);
	}
	if (keycode == XK_Escape)
		close_window(vars);
	return (0);
}

void	event_handler(t_data *data)
{
	mlx_hook(data->window, DESTROY_NOTIFY, 0, close_window, &(*data));
	mlx_key_hook(data->window, key_handler, &(*data));
}

void	move_up(t_data *data)
{
	char	**grid;
	int		i;
	int		j;
	
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
	render_map(*data->img, data->mlx, data->window, *data->map);
}

void	move_down(t_data *data)
{
	char	**grid;
	int		i;
	int		j;
	
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
	render_map(*data->img, data->mlx, data->window, *data->map);
}

void	move_left(t_data *data)
{
	char	**grid;
	int		i;
	int		j;
	
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
	render_map(*data->img, data->mlx, data->window, *data->map);
}

void	move_right(t_data *data)
{
	char	**grid;
	int		i;
	int		j;
	
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
	render_map(*data->img, data->mlx, data->window, *data->map);
}

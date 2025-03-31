/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:08:49 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 16:11:46 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/map.h"
#include "../includes/graphics.h"

void	clean_map(t_map **map)
{
	if (map && *map)
	{
		if ((*map)->grid != NULL)
			free_strs((*map)->grid);
		if ((*map)->fd != -1)
			close((*map)->fd);
		free(*map);
		*map = NULL;
	}
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	free(strs);
	strs = NULL;
}

void	return_error(int err_code, t_map *map)
{
	clean_map(&map);
	display_error(err_code);
	exit (1);
}

void	display_error(int err_code)
{
	if (err_code == ER_CHAR)
		return (ft_putstr_fd("Error\n->Wrong map component(s)\n", 2));
	else if (err_code == ER_MALLOC)
		return (ft_putstr_fd("Error\n->Memory allocation problem\n", 2));
	else if (err_code == ER_MAP_SIZE)
		return (ft_putstr_fd("Error\n->Wrong map\n", 2));
	else if (err_code == ER_COLLECT)
		return (ft_putstr_fd("Error\n->Wrong collectible amount\n", 2));
	else if (err_code == ER_EXIT)
		return (ft_putstr_fd("Error\n->Wrong exit amount\n", 2));
	else if (err_code == ER_PLAYER)
		return (ft_putstr_fd("Error\n->Wrong player amount\n", 2));
	else if (err_code == ER_WALLS)
		return (ft_putstr_fd("Error\n->Walls not properly placed\n", 2));
	else if (err_code == ER_PATH)
		return (ft_putstr_fd("Error\n->Unreachable exit or collectibles\n", 2));
	else
		return ;
}

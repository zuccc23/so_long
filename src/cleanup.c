/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:08:49 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/25 16:22:08 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/map.h"
#include "../includes/graphics.h"

void	clean_map(t_map **map, int fd)
{
	if (*map)
	{
		if ((*map)->grid)
			free_strs((*map)->grid);
		free(*map);
	}
	if (fd != -1)
		close(fd);
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

void	return_error(int err_code, t_map *map, int fd)
{
	clean_map(&map, fd);
	display_error(err_code);
	exit (1);
}

void	display_error(int err_code)
{
	if (err_code == ER_CHAR)
		return (ft_putstr_fd("Error\n->Wrong map component\n", 2));
	else if (err_code == ER_INIT_MAP)
		return (ft_putstr_fd("Error\n->Map couldn't be allocated\n", 2));
	else if (err_code == ER_MAP_SIZE)
		return (ft_putstr_fd("Error\n->Wrong map\n", 2));
	else if (err_code == ER_COLLECT)
		return (ft_putstr_fd("Error\n->Wrong collectible amount\n", 2));
	else if (err_code == ER_EXIT)
		return (ft_putstr_fd("Error\n->Wrong exit amount\n", 2));
	else if (err_code == ER_PLAYER)
		return (ft_putstr_fd("Error\n->Wrong player's starting position\n", 2));
	else if (err_code == ER_WALLS)
		return (ft_putstr_fd("Error\n->Walls not properly placed\n", 2));
	else
		return ;
}

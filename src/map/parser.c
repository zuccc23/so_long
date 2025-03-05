/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:01 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/05 18:58:22 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	init_map(t_map **map, char *mapfile)
{
	int	fd;

	fd = -1;
	allocate_map(&(*map));
		//count height
	//fill_map
	//check_map
	return (0);
}

int	allocate_map(t_map **map)
{
	*map = malloc(sizeof(map));
	if (!*map)
		return (1);
	//
}

int	count_height(t_map **map, char *mapfile, int fd)
{
	int		count;
	char	buffer[10];

	count = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (1);
	//while (gnl != NULL)
	// {
	// 	count++;
	// }
	(*map)->height = count;
}
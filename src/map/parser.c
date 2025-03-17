/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:32:01 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/14 12:30:10 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	init_map(t_map **map, char *mapfile, int fd)
{
	// int	fd;

	// fd = -1;
	// allocate_map(&(*map));
		//count height
	//fill_map
	//check_map
	return (0);
}

int	allocate_map(t_map **map, char *mapfile, int fd)
{
	*map = malloc(sizeof(map));
	if (!*map)
		return (1);
	if (count_height(&(*map), mapfile, &fd) == 1)
		return (1);
	(*map)->grid = malloc(((*map)->height + 1) * sizeof(char **));
	if (!(*map)->grid)
		return (1);
	fill_map(&(*map), mapfile, &fd);
	return (0);
}

int	count_height(t_map **map, char *mapfile, int *fd)
{
	int		count;
	char	buffer[10];

	count = 0;
	*fd = open(mapfile, O_RDONLY);
	if (*fd == -1)
		return (1);
	while (get_next_line(*fd) != NULL)
	{
		count++;
	}
	(*map)->height = count;
	close(*fd);
	return (0);
}

int	fill_map(t_map **map, char *mapfile, int *fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*map)->height)
	{
		(*map)->grid[j] = ft_strdup("get_next_line(*fd)");
		// printf("%s\n", get_next_line(*fd));
		j++;
		i++;
	}
	strs_print((*map)->grid);
	return (0);
}

void	strs_print(char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i] != NULL)
	{
		while (strs[i][j])
		{
			write (1, &strs[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
		j = 0;
	}
	// if (strs[i] == NULL)
	// 	write (1, "null", 4);
}
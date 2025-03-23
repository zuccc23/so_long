/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:37:26 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/23 16:13:33 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

// MAP STRUCTURE //////////////////////////////////////////////////
typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		player_count;
	int		exit_count;
	int		collectible_count;
} t_map;

// PARSER /////////////////////////////////////////////////////////
int		init_map(t_map **map, char *mapfile, int fd);
int		count_height(t_map **map, char *mapfile, int *fd);
int		fill_map(t_map **map, char *mapfile, int *fd);
void	strs_print(char **strs); //delete later
void	remove_nline(char *str);
int		count_width(char **strs, t_map **map);

#endif
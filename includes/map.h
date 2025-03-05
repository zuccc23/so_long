/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:37:26 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/05 18:49:46 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <string.h>
# include "../libs/minilibx-linux/mlx.h"

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

int		allocate_map(t_map **map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:37:26 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/28 16:23:20 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <string.h>
# include <X11/keysym.h>

// MY LIBS ////////////////////////////////////////////////
# include "../libs/gnl/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"
# include "macros.h"

// MAP STRUCTURE //////////////////////////////////////////////////
typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		fd;
} t_map;

// FLOOD FILL STRUCTURE /////////////////////////////////////////
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

// PARSER /////////////////////////////////////////////////////////
int		init_map(t_map **map, char *mapfile);
int		count_height(t_map **map, char *mapfile);
int		count_width(char **strs, t_map **map);
int		fill_map(t_map **map, char *mapfile);
void	strs_print(char **strs); //delete later
void 	remove_nline(char *str);

// VALIDATOR //////////////////////////////////////////////////////
int		valid_characters(t_map *map);
int		ok_char(char c);
int		valid_line(char *str, int i, int height, int width);
int		valid_map(t_map *map);
int		valid_walls(t_map *map);

// VALID SPRITES //////////////////////////////////////////////////
int		valid_sprites(t_map *map);
int		valid_exit_player(t_map *map, char c);
int		valid_collect(t_map *map, char c);

// PATH FINDER ////////////////////////////////////////////////////
void	flood_fill(char **tab, t_point size, t_point begin);
int		path_finder(t_map *map);
int		char_to_fill(char c, t_point size, t_point begin);
void	get_start(t_point *size, t_point *begin, t_map *map);
char	**copy_tab(t_map *map);
int	correct_path(char **tab);

#endif
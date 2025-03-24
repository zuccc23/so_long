/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:37:26 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/24 15:02:24 by dahmane          ###   ########.fr       */
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
void 	remove_nline(char *str);
int		count_width(char **strs, t_map **map);
char	*ft_strnoline(const char *s1);

#endif
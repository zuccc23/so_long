/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:43:48 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 12:19:58 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIBS /////////////////////////////////////////////////
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
# include "map.h"
# include "macros.h"
// # include "graphics.h"

// Forward declaration of t_img (defined in graphics.h)
typedef struct s_img	t_img;

// DATA STRUCTURE ///////////////////////////////////////
typedef struct s_data
{
	void	*mlx;
	void	*window;
	t_img	*img;
	t_map	*map;
}	t_data;

// MOVEMENT ////////////////////////////////////////////////
int		key_handler(int keycode, t_data *vars, t_map *map);
void	event_handler(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

// CLEANUP //////////////////////////////////////////////////
void	clean_map(t_map **map);
void	free_strs(char **strs);
void	return_error(int err_code, t_map *map);
void	display_error(int err_code);

#endif
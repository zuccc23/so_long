/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:43:48 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/25 16:57:38 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// DATA STRUCTURE ///////////////////////////////////////
typedef struct s_data
{
	void	*mlx;
	void	*window;
}	t_data;

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

// MOVEMENT ////////////////////////////////////////////////
int		key_handler(int keycode, t_data *vars);
void	event_handler(t_data *data);

// CLEANUP //////////////////////////////////////////////////
void	clean_map(t_map **map, int fd);
void	free_strs(char **strs);
void	return_error(int err_code, t_map *map, int fd);
void	display_error(int err_code);

#endif
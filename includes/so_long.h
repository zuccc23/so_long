/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:43:48 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/14 12:45:33 by dahmane          ###   ########.fr       */
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

// MY LIBS ////////////////////////////////////////////////
# include "map.h"
# include "graphics.h"
# include "../libs/gnl/get_next_line.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"

// MAIN /////////////////////////////////////////////////////

// CLEANUP //////////////////////////////////////////////////
// void	clean_map(t_map **map, int fd);
// void	free_strs(char **strs);

#endif
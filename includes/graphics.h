/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:41:23 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/18 15:52:45 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "so_long.h"

// IMAGE STRUCTURE ///////////////////////////////////////
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// WINDOW //////////////////////////////////////////////////
void	init_mlx(void **mlx, void **window, int height, int width);
void	*create_window(void *mlx, void *window, int width, int height);
void	close_window(void *mlx, void *window);

// RENDER /////////////////////////////////////////////////
void	put_pixel(t_data *data, int x, int y, int color);
void	draw_rectangle(t_data img, t_map map);

//  /////////////////////////////////////////////////////////
# define WIN_WIDTH 900
# define WIN_HEIGHT 900


#endif
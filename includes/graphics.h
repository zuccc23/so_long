/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:41:23 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/29 11:40:19 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "map.h"
# include "macros.h"
// # include "so_long.h"

// Forward declaration (defined in so_long.h)
typedef struct s_data t_data;

// IMAGE STRUCTURE ///////////////////////////////////////
typedef struct s_img
{
	void	*player;
	void	*collect;
	void	*wall;
	void	*exit;
	void	*tile;
}	t_img;

// WINDOW //////////////////////////////////////////////////
int		init_mlx(void **mlx, void **window, int height, int width);
void	*create_window(void *mlx, void *window, int width, int height);
int		close_window(t_data *data);

// RENDER /////////////////////////////////////////////////
// void	put_pixel(t_data *data, int x, int y, int color);
// void	draw_rectangle(t_data img, t_map map, int x, int y, int color);
// void	render_map_test(t_data img, t_map map);
// void	calc_square_size(t_map map, int *height, int *width);
void	render_map(t_img img, void *mlx, void *window, t_map map);
void	*get_right_img(char c, t_img img);

// TEXTURES /////////////////////////////////////////////////
void	*create_img(void *mlx, char *relative_path, int width, int height);
int		init_sprites(void *mlx, t_img *images);

// WINDOW SIZE /////////////////////////////////////////////////
# define WIN_WIDTH 900
# define WIN_HEIGHT 900
# define SPRITE_SIZE 80

// ERRORS /////////////////////////////////////////////////////
// # define ER_OK 0
// # define ER_MLX_INIT -1
// # define ERR_MLX_NWIN -2
// # define ERR_FILE_TO_IMG -3

#endif
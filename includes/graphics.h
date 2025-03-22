/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:41:23 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/22 15:58:50 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "so_long.h"
#include "map.h"

// IMAGE STRUCTURE ///////////////////////////////////////
typedef struct s_img
{
	void	*player;
	void	*collect;
	void	*wall;
	void	*exit;
	void	*tile;
}	t_img;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }	t_data;

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
# define ER_OK 0
# define ER_MLX_INIT -1
# define ERR_MLX_NWIN -2
# define ERR_FILE_TO_IMG -3

#endif
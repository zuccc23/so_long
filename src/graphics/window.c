/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:48:46 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/29 13:17:29 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"
#include "../../includes/map.h"
#include "../../includes/so_long.h"

int	init_mlx(void **mlx, void **window, int height, int width)
{
	int	height_win;
	int	width_win;

	ft_printf("--INIT MLX--\n");
	*mlx = mlx_init();
	if (!(*mlx))
		return (ER_MLX_INIT);
	height_win = SPRITE_SIZE * height;
	width_win = SPRITE_SIZE  * width;
	*window = create_window(*mlx, *window, width_win, height_win);
	if (!(*window))
		return (ERR_MLX_NWIN);
	return (ER_OK);
}

void	*create_window(void *mlx, void *window, int width, int height)
{
	ft_printf("--CREATE WINDOW--\n");

	window = mlx_new_window(mlx, width, height, "So Long!");
	if (!window)
		return (NULL);
	return (window);
}

int	close_window(t_data *data)
{
	// FREE MAP
	clean_map(&(data->map));
	
	// FREE IMAGES
	mlx_destroy_image(data->mlx, data->img->collect);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->exit);
	mlx_destroy_image(data->mlx, data->img->player);
	mlx_destroy_image(data->mlx, data->img->tile);
	
	// DESTROY WINDOW
	mlx_destroy_window(data->mlx, data->window);

	// DESTROY DISPLAY
	mlx_destroy_display(data->mlx);
	
	// FREE MLX POINTER
	free(data->mlx);
	
	exit(0);
	return (0);
}

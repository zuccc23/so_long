/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:48:46 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/20 13:06:41 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"
#include "../../includes/map.h"

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

	window = mlx_new_window(mlx, width, height, "Title!");
	if (!window)
		return (NULL);
	return (window);
}

void	close_window(void *mlx, void *window)
{
	//cleanup needed before closing window 
	mlx_destroy_window(mlx, window);
	//maybe err code if fail
}
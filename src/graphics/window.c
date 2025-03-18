/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:48:46 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/18 15:28:25 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

void	init_mlx(void **mlx, void **window, int height, int width)
{
	int	height_win;
	int	width_win;

	ft_printf("--INIT MLX--\n");
	*mlx = mlx_init();
	height_win = (WIN_HEIGHT / height) * height;
	width_win = (WIN_WIDTH / width) * width;
	*window = create_window(*mlx, *window, height_win, width_win);
	
}

void	*create_window(void *mlx, void *window, int width, int height)
{
	ft_printf("--CREATE WINDOW--\n");

	window = mlx_new_window(mlx, width, height, "Title!");
	if (!window)
		return (NULL); //add err code
	return (window);
}

void	close_window(void *mlx, void *window)
{
	//cleanup needed before closing window 
	mlx_destroy_window(mlx, window);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:48:46 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/17 16:16:49 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst; // a pointer to the address of img

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	//puts you at the right pixel
	*(unsigned int*)dst = color; //change the color of the pixel
}

void	init_mlx(void)
{
	void	*mlx;
	void	*window;
	t_data	img;
	int	i = 0;
	int	j = 0;
	
	printf("--INIT MLX--\n");
	mlx = mlx_init();
	window = mlx_new_window(mlx, 960, 960, "Title!");
	
	img.img = mlx_new_image(mlx, 960, 960);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	printf("bits/pixel: %d line length: %d endian: %d\n", img.bits_per_pixel, img.line_length, img.endian);
	while (i < 960)
	{
		j = 0;
		while (j < IMG_LENGTH)
		{
			put_pixel(&img, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
}
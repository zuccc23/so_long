/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:36:36 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/20 14:57:46 by dahmane          ###   ########.fr       */
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

void	draw_rectangle(t_data img, t_map map, int x, int y, int color)
{
	int height;
	int	width;
	int	x_temp;
	int	i;
	int	j;

	j = 0;
	calc_square_size(map, &height, &width);
	while (j < height)
	{
		x_temp = x;
		i = 0;
		while (i < width)
		{
			put_pixel(&img, x_temp, y, color);
			x_temp++;
			i++;
		}
		y++;
		j++;
	}
}

void	render_map(t_data img, t_map map)
{
	int	square_width;
	int	square_height;
	int	j;
	int	i;
	int	x = 0;
	int	y = 0;

	// add a get_color(char c); function
	i = 0;
	calc_square_size(map, &square_height, &square_width);
	while (map.grid[i])
	{
		j = 0;
		while (map.grid[i][j])
		{
			if (map.grid[i][j] == '1')
			{
				draw_rectangle(img, map, x, y, 0x00c5c8f4);
			}
			if (map.grid[i][j] == 'P')
			{
				draw_rectangle(img, map, x, y, 0x00f6bde2);
			}
			if (map.grid[i][j] == 'C')
			{
				draw_rectangle(img, map, x, y, 0x00f4f6bd);
			}
			if (map.grid[i][j] == 'E')
			{
				draw_rectangle(img, map, x, y, 0x00f6dabd );
			}
			j++;
			x += square_width;
		}
		i++;
		y += square_height - 1;
	}
}

void	calc_square_size(t_map map, int *height, int *width)
{
	*height = (WIN_HEIGHT / map.height);
	*width = (WIN_WIDTH / map.width);
}
// void	render_map()
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:36:36 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/18 15:55:13 by dahmane          ###   ########.fr       */
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

void	draw_rectangle(t_data img, t_map map)
{
	int	i;
	int	j;
	int height;
	int	width;

	i = 0;
	height = (WIN_HEIGHT / map.height);
	width = (WIN_WIDTH / map.width);
	
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			put_pixel(&img, j, i, 0x00FF00FF);
			j++;
		}
		i++;
	}
	
}

void	render_map()
{
	//
}

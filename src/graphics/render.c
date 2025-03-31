/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:36:36 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 12:22:45 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

void	render_map(t_img img, void *mlx, void *window, t_map map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*correct_image;

	i = 0;
	y = 0;
	while (map.grid[i])
	{
		j = 0;
		x = 0;
		while (map.grid[i][j])
		{
			correct_image = get_right_img(map.grid[i][j], img);
			mlx_put_image_to_window(mlx, window, correct_image, x, y);
			x += SPRITE_SIZE;
			j++;
		}
		i++;
		y += SPRITE_SIZE;
	}
}

void	*get_right_img(char c, t_img img)
{
	void	*img_to_return;

	if (c == '1')
		img_to_return = img.wall;
	if (c == '0')
		img_to_return = img.tile;
	if (c == 'P')
		img_to_return = img.player;
	if (c == 'E')
		img_to_return = img.exit;
	if (c == 'C')
		img_to_return = img.collect;
	return (img_to_return);
}

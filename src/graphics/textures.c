/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:27:25 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/22 13:40:39 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

void	*create_img(void *mlx, char *relative_path, int width, int height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &width, &height);
	if (!img)
		return (NULL);
	return (img);
}

int	init_sprites(void *mlx, t_img *images)
{
	int	width;
	int	height;
	
	(*images).player = create_img(mlx, "assets/sprites/bingus1.xpm", width, height);
	if (!(*images).player)
		return (ERR_FILE_TO_IMG);
	(*images).wall = create_img(mlx, "assets/sprites/flame2.xpm", width, height);
	if (!(*images).wall)
		return (ERR_FILE_TO_IMG);
	(*images).collect = create_img(mlx, "assets/sprites/floppa3.xpm", width, height);
	if (!(*images).collect)
		return (ERR_FILE_TO_IMG);
	(*images).exit = create_img(mlx, "assets/sprites/froggy_chair2.xpm", width, height);
	if (!(*images).exit)
		return (ERR_FILE_TO_IMG);
	(*images).tile = create_img(mlx, "assets/sprites/block1.xpm", width, height);
	if (!(*images).tile)
		return (ERR_FILE_TO_IMG);
	return (ER_OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:27:25 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/20 11:26:05 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graphics.h"

void	*init_img(void *mlx, char *relative_path, int width, int height)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, relative_path, &width, &height);
	if (!img)
		return (NULL);
	return (img);
}
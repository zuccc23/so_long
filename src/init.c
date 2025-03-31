/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:18:08 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 16:12:46 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/map.h"
#include "../includes/graphics.h"

void	init_and_parse_map(t_map **map, char *mapfile)
{
	int		err_code;

	*map = NULL;
	err_code = 0;
	err_code = init_map(&(*map), mapfile);
	if (err_code != ER_OK)
		return_error(err_code, *map);
	err_code = valid_map(*map);
	if (err_code != ER_OK)
		return_error(err_code, *map);
	err_code = path_finder(*map);
	if (err_code != ER_OK)
		return_error(err_code, *map);
}

void	window_and_render(t_img *img, void **mlx, void **window, t_map **map)
{
	int	err_code;

	err_code = 0;
	err_code = init_mlx(&(*mlx), &(*window), (*map)->height, (*map)->width);
	if (err_code != ER_OK)
		return_error(err_code, *map);
	err_code = init_sprites(*mlx, &(*img));
	if (err_code != ER_OK)
		return_error(err_code, *map);
	render_map(*img, *mlx, *window, **map);
}

int	check_ber(char *str)
{
	char	*ber;

	ber = ft_strchr(str, '.');
	if (!ber)
		return (1);
	if (ft_strlen(ber) != 4)
		return (1);
	if (ft_strncmp(ber, ".ber", 4) != 0)
		return (1);
	return (0);
}

t_data	init_data(t_img *img, void **mlx, void **window, t_map **map)
{
	t_data	data;

	data.map = *map;
	data.window = *window;
	data.mlx = *mlx;
	data.img = &(*img);
	return (data);
}

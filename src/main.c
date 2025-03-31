/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:27:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 16:11:36 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/map.h"
#include "../includes/graphics.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_img	img;
	t_data	data;
	void	*mlx;
	void	*window;

	map = NULL;
	mlx = NULL;
	window = NULL;
	img.collect = NULL;
	if (argc != 2 || check_ber(argv[1]) == 1)
		return (ft_printf("Error\n->No map provided, or wrong extension\n"));
	init_and_parse_map(&map, argv[1]);
	window_and_render(&img, &mlx, &window, &map);
	data = init_data(&img, &mlx, &window, &map);
	event_handler(&data);
	mlx_loop(mlx);
}

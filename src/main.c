/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:27:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/22 17:42:47 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/map.h"
#include "../includes/graphics.h"

int	main(int argc, char **argv)
{	
	// PARSING //////////////////////////////////////////////
	// t_map	*map = NULL;
	// char	*mapfile;
	// int fd = -1;
	
	// if (argc != 2)
	// 	return (0);
	// // printf("hello world\n");
	// allocate_map(&map, argv[1], fd);
	// printf("test");
	// // printf("%d\n", map->height);
	
	// GRAPHIC SETUP //////////////////////////////////////////
	// MAP //
	t_map	*map = NULL;
	char *map_temp[] = {"11111", "1P001", "1C001", "10CE1", "11111", NULL};
	map = malloc(sizeof(t_map));
	map->grid = map_temp;
	map->height = 5;
	map->width = 5;
	
	ft_printf("--MAP--");
	ft_printf("\n");
	strs_print(map->grid);
	ft_printf("\n");

	// // WINDOW //
	void	*mlx = NULL;
	void	*window = NULL;
	if (init_mlx(&mlx, &window, map->height, map->width) != ER_OK)
		return (ft_printf("error"));
	
	// // BASIC COLOR IMAGE //
	// t_data	img;
	// int	i = 0;
	// int	j = 0;
	
	// img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// ft_printf("bits/pixel: %d line length: %d endian: %d\n", img.bits_per_pixel, img.line_length, img.endian);
	// while (i < WIN_HEIGHT)
	// {
	// 	j = 0;
	// 	while (j < WIN_WIDTH)
	// 	{
	// 		put_pixel(&img, j, i, 0x00c5f4ce);
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	// DRAW STUFF //
	// render_map_test(img, *map);

	// ADD IMAGES
	// void	*bingus = NULL;
	// void	*floppa = NULL;
	// int	width;
	// int	height;
	
	// bingus = init_img(mlx, "assets/sprites/bingus5.xpm", width, height);
	// if (!bingus)
	// 	return (ft_printf("fail"));
	
	// floppa = init_img(mlx, "assets/sprites/floppa2.xpm", width, height);
	// if (!floppa)
	// 	return (ft_printf("fail"));
	
		// SHOW WINDOW
	// mlx_put_image_to_window(mlx, window, bingus, 0, 0);
	// mlx_put_image_to_window(mlx, window, bingus, 60, 0);
	// mlx_put_image_to_window(mlx, window, floppa, 0, 0);
	// mlx_put_image_to_window(mlx, window, floppa, 0, 120);

	// RENDER MAP
	t_img img;
	
	// img.player = create_img(mlx, "assets/sprites/bingus1.xpm", width, height);
	// img.wall = create_img(mlx, "assets/sprites/flame2.xpm", width, height);
	// img.collect = create_img(mlx, "assets/sprites/floppa3.xpm", width, height);
	// img.exit = create_img(mlx, "assets/sprites/froggy_chair2.xpm", width, height);
	// img.tile = create_img(mlx, "assets/sprites/block1.xpm", width, height);
	
	if (init_sprites(mlx, &img) != ER_OK)
		return (ft_printf("error"));
	render_map(img, mlx, window, *map);

	// EVENTS
	t_data data;
	data.window = window;
	data.mlx = mlx;
	
	mlx_hook(data.window, DESTROY_NOTIFY, 0, close_window, &data);
	mlx_key_hook(data.window, key_handler, &data);
	
	// LOOP
	mlx_loop(mlx);
}

/*STUFF TO FREE :
-map
-t_img img
-window (close)
-mlx?
*/
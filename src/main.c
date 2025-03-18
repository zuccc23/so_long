/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:27:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/18 15:53:04 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

	// WINDOW //
	void	*mlx;
	void	*window;
	init_mlx(&mlx, &window, 5, 5);

	// IMAGE //
	t_data	img;
	int	i = 0;
	int	j = 0;
	
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// ft_printf("bits/pixel: %d line length: %d endian: %d\n", img.bits_per_pixel, img.line_length, img.endian);
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			put_pixel(&img, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}
	
	// DRAW STUFF //
	// int height;
	// int	width;

	// i = 0;
	// height = (map->height / 1000);
	// width = (map->width / 900);
	
	// while (i < height)
	// {
	// 	j = 0;
	// 	while (j < width)
	// 	{
	// 		put_pixel(&img, j, i, 0x00FF00FF);
	// 		j++;
	// 	}
	// 	i++;
	// }
	draw_rectangle(img, *map);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
	
}

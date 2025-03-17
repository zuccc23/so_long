/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:27:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/14 13:25:36 by dahmane          ###   ########.fr       */
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
	
	printf("--MAP--");
	printf("\n");
	strs_print(map->grid);
	printf("\n");

	// WINDOW //
	init_mlx();
	
}

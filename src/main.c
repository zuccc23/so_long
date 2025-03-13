/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:27:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/13 23:00:01 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map = NULL;
	char	*mapfile;
	int fd = -1;
	
	if (argc != 2)
		return (0);
	// printf("hello world\n");
	allocate_map(&map, argv[1], fd);
	printf("test");
	// printf("%d\n", map->height);
}

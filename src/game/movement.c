/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:43:09 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 12:15:17 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/graphics.h"

int	key_handler(int keycode, t_data *vars, t_map *map)
{
	if (keycode == XK_w)
	{
		ft_printf("up!\n");
		move_up(vars);
	}
	if (keycode == XK_a)
	{
		ft_printf("left!\n");
		move_left(vars);
	}
	if (keycode == XK_s)
	{
		ft_printf("down!\n");
		move_down(vars);
	}
	if (keycode == XK_d)
	{
		ft_printf("right!\n");
		move_right(vars);
	}
	if (keycode == XK_Escape)
		close_window(vars);
	return (0);
}

void	event_handler(t_data *data)
{
	mlx_hook(data->window, DESTROY_NOTIFY, 0, close_window, &(*data));
	mlx_key_hook(data->window, key_handler, &(*data));
}

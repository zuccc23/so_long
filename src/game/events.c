/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:43:09 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/31 16:15:03 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/graphics.h"

int	key_handler(int keycode, t_data *vars)
{
	static int	count;

	if (keycode == XK_w)
		move_up(vars, &count);
	if (keycode == XK_a)
		move_left(vars, &count);
	if (keycode == XK_s)
		move_down(vars, &count);
	if (keycode == XK_d)
		move_right(vars, &count);
	if (keycode == XK_Escape)
		close_window(vars);
	render_map(*vars->img, vars->mlx, vars->window, *vars->map);
	return (0);
}

void	event_handler(t_data *data)
{
	mlx_hook(data->window, DESTROY_NOTIFY, 0, close_window, &(*data));
	mlx_key_hook(data->window, key_handler, &(*data));
}

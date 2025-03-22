/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:43:09 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/22 18:24:10 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/graphics.h"

int	key_handler(int keycode, t_data *vars)
{
	//add movement count
	if (keycode == XK_w)
		ft_printf("up!\n");
	if (keycode == XK_a)
		ft_printf("left!\n");
	if (keycode == XK_s)
		ft_printf("down!\n");
	if (keycode == XK_d)
		ft_printf("right!\n");
	if (keycode == XK_Escape)
		close_window(vars);
	return (0);
}

void	event_handler(t_data *data)
{
	mlx_hook(data->window, DESTROY_NOTIFY, 0, close_window, &(*data));
	mlx_key_hook(data->window, key_handler, &(*data));
}

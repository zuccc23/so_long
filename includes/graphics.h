/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:41:23 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/17 16:18:18 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "so_long.h"

// IMAGE STRUCTURE ///////////////////////////////////////
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


// WINDOW //////////////////////////////////////////////////
void	init_mlx(void);

//  /////////////////////////////////////////////////////////
# define IMG_LENGTH 960
# define IMG_HEIGHT 960


#endif
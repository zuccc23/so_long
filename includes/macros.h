/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:17:54 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/28 15:07:22 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ER_OK 0

// WINDOW SIZE /////////////////////////////////////////////////
# define WIN_WIDTH 900
# define WIN_HEIGHT 900
# define SPRITE_SIZE 80

// EVENTS CODE /////////////////////////////////////////////
# define DESTROY_NOTIFY 17
# define KEY_PRESS 2

// MLX ERRORS /////////////////////////////////////////////////////
# define ER_MLX_INIT -1
# define ERR_MLX_NWIN -2
# define ERR_FILE_TO_IMG -3

// MAP ERRORS ///////////////////////////////////////////////////
# define ER_MALLOC -10
# define ER_PLAYER -11
# define ER_WALLS -12
# define ER_COLLECT -13
# define ER_EXIT -14
# define ER_MAP_SIZE -15
# define ER_CHAR -16
# define ER_PATH -17

#endif
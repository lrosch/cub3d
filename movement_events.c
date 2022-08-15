/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:47:23 by lrosch            #+#    #+#             */
/*   Updated: 2022/06/28 15:57:11 by lrosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_d(t_game *game)
{
	double	or_y_tmp;
	double	or_x_tmp;
	int		i;

	i = 0;
	or_x_tmp = game->or->x;
	or_y_tmp = game->or->y;
	while (i < 90)
	{
		or_x_tmp = cos(1 * PI / 180) * or_x_tmp - sin(1 * PI / 180)
			* or_y_tmp;
		or_y_tmp = sin(1 * PI / 180) * or_x_tmp + cos(1 * PI / 180)
			* or_y_tmp;
		i++;
	}
	if (game->map[(int)(game->py + 20 * or_y_tmp) / 64]
	[(int)(game->px + 20 * or_x_tmp) / 64] != '1')
	{
		game->py = game->py + 5 * or_y_tmp;
		game->px = game->px + 5 * or_x_tmp;
	}
}

void	event_a(t_game *game)
{
	double	or_y_tmp;
	double	or_x_tmp;
	int		i;

	i = 0;
	or_x_tmp = game->or->x;
	or_y_tmp = game->or->y;
	while (i < 90)
	{
		or_x_tmp = cos(-1 * PI / 180) * or_x_tmp - sin(-1 * PI / 180)
			* or_y_tmp;
		or_y_tmp = sin(-1 * PI / 180) * or_x_tmp + cos(-1 * PI / 180)
			* or_y_tmp;
		i++;
	}
	if (game->map[(int)(game->py + 20 * or_y_tmp) / 64]
	[(int)(game->px + 20 * or_x_tmp) / 64] != '1')
	{
		game->py = game->py + 5 * or_y_tmp;
		game->px = game->px + 5 * or_x_tmp;
	}
}

void	event_w(t_game *game)
{
	if (game->map[(int)(game->py + 20 * game->or->y) / 64]
	[(int)(game->px + 20 * game->or->x) / 64] != '1')
	{
		game->py = game->py + 5 * game->or->y;
		game->px = game->px + 5 * game->or->x;
	}
}

void	event_s(t_game *game)
{
	if (game->map[(int)(game->py - 20 * game->or->y) / 64]
	[(int)(game->px - 20 * game->or->x) / 64] != '1')
	{
		game->py = game->py - 5 * game->or->y;
		game->px = game->px - 5 * game->or->x;
	}
}
